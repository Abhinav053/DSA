class Solution {
    vector<vector<int>> vis;
    int m, n;

    bool f(vector<vector<char>>& board, string &word, int k, int i, int j) {

        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;

        if (vis[i][j])
            return false;

        if (board[i][j] != word[k])
            return false;
        if (k == word.size() - 1)
            return true;

        vis[i][j] = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int d = 0; d < 4; d++) {
            int x = i + dr[d];
            int y = j + dc[d];

            if (f(board, word, k + 1, x, y)) {
                vis[i][j] = 0;
                return true;
            }
        }

        vis[i][j] = 0;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        n = board[0].size();

        vis.assign(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (f(board, word, 0, i, j))
                    return true;
            }
        }

        return false;
    }
};