class Solution {
    int dp[200005][2];

    int f(string& s, int i, int prev) {
        if (i >= s.size())
            return 0;

        if (dp[i][prev] != -1)
            return dp[i][prev];

        if (s[i] == '1') {

            if (prev == 0) {
                return dp[i][prev] = min(
                    f(s, i + 1, 1),           // keep 1
                    1 + f(s, i + 1, 0)        // flip 1 -> 0
                );
            }
            else {
                // prev = 1, so cannot choose 0
                return dp[i][prev] = f(s, i + 1, 1);
            }

        }
        else { // s[i] == '0'

            if (prev == 1) {
                // Cannot keep 0, must flip 0 -> 1
                return dp[i][prev] = 1 + f(s, i + 1, 1);
            }
            else {
                return dp[i][prev] = min(
                    1 + f(s, i + 1, 1),        // flip 0 -> 1
                    f(s, i + 1, 0)              // keep 0
                );
            }
        }
    }

public:
    int minFlipsMonoIncr(string s) {
        memset(dp, -1, sizeof(dp));
        return f(s, 0, 0);
    }
};