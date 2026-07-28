class Solution {
    int f(vector<vector<int>>& ans, int i, vector<int>& dp) {
        if (i >= ans.size()) return 0;

        if (dp[i] != -1) return dp[i];

       
        auto k = lower_bound(
            ans.begin() + i + 1,
            ans.end(),
            ans[i][1],
            [](const vector<int>& a, int endTime) {
                return a[0] < endTime;
            }
        );

        int nextIndex = k - ans.begin();

      
        int pick = ans[i][2] + f(ans, nextIndex, dp);

      
        int leave = f(ans, i + 1, dp);

        return dp[i] = max(pick, leave);
    }

public:
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& p) {
        int n = st.size();

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            ans.push_back({st[i], et[i], p[i]});
        }

       
        sort(ans.begin(), ans.end());

        vector<int> dp(n, -1);

        return f(ans, 0, dp);
    }
};