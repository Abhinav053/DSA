
class Solution {
    vector<vector<int>> vis;
    int m, n;

    bool f(vector<vector<char>>& board, string& word,
           int i, int j, int k) {

        if (k >= word.size()) return true;

        if (i < 0 || i >= m || j < 0 || j >= n ||
            vis[i][j] || board[i][j] != word[k]) {
            return false;
        }

        vis[i][j] = 1;

        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};

        for (int l = 0; l < 4; l++) {
            int xx = i + x[l];
            int yy = j + y[l];

            if (f(board, word, xx, yy, k + 1)) {
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
                if (f(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
