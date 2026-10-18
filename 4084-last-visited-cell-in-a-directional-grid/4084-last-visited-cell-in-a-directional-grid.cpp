class Solution {
    int m, n;
    pair<int, int> last;

    void f(vector<vector<char>>& grid,
           vector<vector<int>>& vis, int i, int j) {

        if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j]) {
            return;
        }

        vis[i][j] = 1;
        last = {i, j};

        if (grid[i][j] == 'L')
            f(grid, vis, i, j - 1);
        else if (grid[i][j] == 'R')
            f(grid, vis, i, j + 1);
        else if (grid[i][j] == 'U')
            f(grid, vis, i - 1, j);
        else if (grid[i][j] == 'D')
            f(grid, vis, i + 1, j);
    }

public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        last = {0, 0};
        f(grid, vis, 0, 0);

        return {last.first, last.second};
    }
};