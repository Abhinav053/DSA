class Solution {
    int m, n;
    const int INF = 1e9;

    // 0 = up
    // 1 = down
    // 2 = left
    // 3 = right
    // 4 = no previous direction

    int f(vector<vector<int>>& grid,
          int k,
          int dir,
          int i,
          int j,
          vector<vector<vector<vector<int>>>>& dp) {

        if (i < 0 || i >= m || j < 0 || j >= n)
            return INF;

        if (i == m - 1 && j == n - 1)
            return grid[i][j];

        if (dp[i][j][k][dir] != -1)
            return dp[i][j][k][dir];

        int ans = INF;

        // UP
        if (dir == 4 || dir == 0) {
            ans = min(ans,
                grid[i][j] +
                f(grid, k, 0, i - 1, j, dp));
        }
        else if (k > 0) {
            ans = min(ans,
                grid[i][j] +
                f(grid, k - 1, 0, i - 1, j, dp));
        }

        // DOWN
        if (dir == 4 || dir == 1) {
            ans = min(ans,
                grid[i][j] +
                f(grid, k, 1, i + 1, j, dp));
        }
        else if (k > 0) {
            ans = min(ans,
                grid[i][j] +
                f(grid, k - 1, 1, i + 1, j, dp));
        }

        // LEFT
        if (dir == 4 || dir == 2) {
            ans = min(ans,
                grid[i][j] +
                f(grid, k, 2, i, j - 1, dp));
        }
        else if (k > 0) {
            ans = min(ans,
                grid[i][j] +
                f(grid, k - 1, 2, i, j - 1, dp));
        }

        // RIGHT
        if (dir == 4 || dir == 3) {
            ans = min(ans,
                grid[i][j] +
                f(grid, k, 3, i, j + 1, dp));
        }
        else if (k > 0) {
            ans = min(ans,
                grid[i][j] +
                f(grid, k - 1, 3, i, j + 1, dp));
        }

        return dp[i][j][k][dir] = ans;
    }

public:
    int minCost(vector<vector<int>>& grid, int k) {

        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<vector<int>>>> dp(
            m,
            vector<vector<vector<int>>>(
                n,
                vector<vector<int>>(
                    k + 1,
                    vector<int>(5, -1)
                )
            )
        );

        int ans = f(grid, k, 4, 0, 0, dp);

        return ans >= INF ? -1 : ans;
    }
};