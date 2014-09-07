class Solution {
    public:
        void solve(vector<vector<char>> &board) {
            if (board.empty()) return;
            int n = board.size();
            int m = board[0].size();
            for (int i = 0; i < n; ++i) {
                bfs(board, i, 0);
                bfs(board, i, m-1);
            }
            for (int j = 0; j < m; ++j) {
                bfs(board, 0, j);
                bfs(board, n-1, j);
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    board[i][j] = (board[i][j] == 'L') ? 'O' : 'X';
                }
            }
        }

        void bfs(vector<vector<char>> &board, int i, int j) {
            int n = board.size();
            int m = board[0].size();
            if (i < 0 || i >= n || j < 0 || j >= m) return;
            if (board[i][j] == 'O') {
                board[i][j] = 'L';
                bfs(board, i+1, j);
                bfs(board, i-1, j);
                bfs(board, i, j+1);
                bfs(board, i, j-1);
            }
        }
};
