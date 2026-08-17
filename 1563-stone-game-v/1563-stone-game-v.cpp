class Solution {
    int dp[501][501];

    int f(vector<int>& a, int l, int r, vector<int>& prefix) {
        if (l == r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        for (int i = l; i < r; i++) {
            int left = prefix[i + 1] - prefix[l];
            int right = prefix[r + 1] - prefix[i + 1];

            if (left < right) {
                ans = max(ans, left + f(a, l, i, prefix));
            }
            else if (left > right) {
                ans = max(ans, right + f(a, i + 1, r, prefix));
            }
            else {
                ans = max(ans, left + f(a, l, i, prefix));
                ans = max(ans, right + f(a, i + 1, r, prefix));
            }
        }

        return dp[l][r] = ans;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        memset(dp, -1, sizeof(dp));

        return f(stoneValue, 0, n - 1, prefix);
    }
};