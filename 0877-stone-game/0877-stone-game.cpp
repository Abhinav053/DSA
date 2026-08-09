class Solution {
    int dp[501][501];

    int f(vector<int>& piles, int i, int j) {

        if (i > j)
            return 0;

        if (i == j)
            return piles[i];

        if (dp[i][j] != -1)
            return dp[i][j];

        int take_i = piles[i] + min(f(piles, i + 2, j), f(piles, i + 1, j - 1));

        int take_j = piles[j] + min(f(piles, i, j - 2), f(piles, i + 1, j - 1));

        return dp[i][j] = max(take_i, take_j);
    }

public:
    bool stoneGame(vector<int>& piles) {

        memset(dp, -1, sizeof(dp));

        int alice = f(piles, 0, piles.size() - 1);

        int total = 0;

        for (int x : piles)
            total += x;

        int bob = total - alice;

        return alice > bob;
    }
};