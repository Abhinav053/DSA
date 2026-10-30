class Solution {
    vector<vector<int>> dp;

    bool f(string &s, vector<string>& wordDict, int i, int j) {
        if (i >= s.size()) {
            return j >= s.size();
        }

        if (dp[i][j] != -1) return dp[i][j];

        string str = s.substr(j, i - j + 1);

        bool take = false;
        bool leave = false;

        if (find(wordDict.begin(), wordDict.end(), str) != wordDict.end()) {
            take = f(s, wordDict, i + 1, i + 1);
        }

        leave = f(s, wordDict, i + 1, j);

        return dp[i][j] = (take || leave);
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        dp.assign(n, vector<int>(n, -1));

        return f(s, wordDict, 0, 0);
    }
};