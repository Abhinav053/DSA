class Solution {
    int lcs(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = 1 + lcs(i - 1, j - 1, s1, s2, dp);
        else
            return dp[i][j] = max(
                lcs(i - 1, j, s1, s2, dp),
                lcs(i, j - 1, s1, s2, dp)
            );
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();

        
        vector<vector<int>> dp(n, vector<int>(m, -1));

      
        lcs(n - 1, m - 1, str1, str2, dp);

       
        int i = n - 1, j = m - 1;
        string res;

        while (i >= 0 && j >= 0) {
            if (str1[i] == str2[j]) {
                res.push_back(str1[i]);
                i--;
                j--;
            } else if (i > 0 && (j == 0 || dp[i - 1][j] >= dp[i][j - 1])) {
                res.push_back(str1[i]);
                i--;
            } else {
                res.push_back(str2[j]);
                j--;
            }
        }

        while (i >= 0) {
            res.push_back(str1[i--]);
        }
        while (j >= 0) {
            res.push_back(str2[j--]);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};