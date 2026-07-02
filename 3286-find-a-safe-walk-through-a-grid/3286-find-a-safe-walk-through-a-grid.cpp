class Solution {
    int m, n;
    vector<vector<int>> vis;
    vector<vector<vector<int>>> dp;


    bool f(vector<vector<int>>& grid, int health, int i, int j) {

       
        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;

        
        if (vis[i][j])
            return false;
        
       
        health -= grid[i][j];

        if (health <= 0)
            return false;

        if (i == m - 1 && j == n - 1)
            return true;
if(dp[i][j][health]!=-1)return dp[i][j][health];
        vis[i][j] = 1;

        bool ans =
            f(grid, health, i + 1, j) ||
            f(grid, health, i - 1, j) ||
            f(grid, health, i, j + 1) ||
            f(grid, health, i, j - 1);

        vis[i][j] = 0;

        return dp[i][j][health]=ans;
    }

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m = grid.size();
        n = grid[0].size();

        vis.assign(m, vector<int>(n, 0));
        dp.assign(m,
                  vector<vector<int>>(n,
                  vector<int>(health + 1, -1)));


        return f(grid, health, 0, 0);
    }
};