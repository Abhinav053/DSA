class Solution {
    int dp[100001][2];

    bool f(int n, int turn) {
        if (n == 0) {
            return turn == 0;
        }

        if (dp[n][turn] != -1)
            return dp[n][turn];

        for (int i = 1; i * i <= n; i++) {
            if (turn == 1) {
                
                if (f(n - i * i, 0))
                    return dp[n][turn] = true;
            }
            else {
                
                if (!f(n - i * i, 1))
                    return dp[n][turn] = false;
            }
        }

        return dp[n][turn] = (turn == 0);
    }

public:
    bool winnerSquareGame(int n) {
        memset(dp, -1, sizeof(dp));
        return f(n, 1);
    }
};