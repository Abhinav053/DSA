class Solution {
public:

    bool f(string& s, int open, int close, int i,
           vector<vector<vector<int>>>& dp) {

        if (open < close)
            return false;

        if (i == s.size())
            return open == close;

        if (dp[i][open][close] != -1)
            return dp[i][open][close];

        bool ans;

        if (s[i] == '(') {

            ans = f(s, open + 1, close, i + 1, dp);

        }
        else if (s[i] == ')') {

            ans = f(s, open, close + 1, i + 1, dp);

        }
        else {

            // '*' -> '('
            bool op = f(s, open + 1, close, i + 1, dp);

            // '*' -> ')'
            bool cl = f(s, open, close + 1, i + 1, dp);

            // '*' -> empty
            bool star = f(s, open, close, i + 1, dp);

            ans = op || cl || star;
        }

        return dp[i][open][close] = ans;
    }

    bool checkValidString(string s) {

        int n = s.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(n + 1,
            vector<int>(n + 1, -1))
        );

        return f(s, 0, 0, 0, dp);
    }
};