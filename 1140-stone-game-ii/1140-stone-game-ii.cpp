class Solution {
    int n;
    int dp[101][101][2];

    int ans(vector<int>& piles, int i, int m, int person) {
        if (i >= n) return 0;

        if (dp[i][m][person] != -1)
            return dp[i][m][person];

        int stone = 0;
        int pick = (person == 0) ? INT_MIN : INT_MAX;

        for (int j = 1; j <= 2 * m && i + j - 1 < n; j++) {
            stone += piles[i + j - 1];

            if (person == 0) {
                pick = max(pick, stone + ans(piles, i + j, max(m, j), 1));
            } else {
                pick = min(pick, ans(piles, i + j, max(m, j), 0));
            }
        }

        return dp[i][m][person] = pick;
    }

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp, -1, sizeof(dp));
        return ans(piles, 0, 1, 0);
    }
};