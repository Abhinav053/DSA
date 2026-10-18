class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int x = 0, y = 0;
        vis[x][y] = 1;

        while (true) {
            int nx = x, ny = y;

            if (grid[x][y] == 'L') ny--;
            else if (grid[x][y] == 'R') ny++;
            else if (grid[x][y] == 'U') nx--;
            else if (grid[x][y] == 'D') nx++;

            if (nx < 0 || nx >= m || ny < 0 || ny >= n ||
                vis[nx][ny]) {
                return {x, y};
            }

            x = nx;
            y = ny;
            vis[x][y] = 1;
        }
    }
};