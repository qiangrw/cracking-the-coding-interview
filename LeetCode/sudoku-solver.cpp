class Solution {
    public:
        void solveSudoku(vector<vector<char> > &board) {
            solve(board);
        }

        bool isValid(vector<vector<char> > &board, int row, int col) {
            for (int j = 0; j < 9; j++) if (j != col && board[row][j] == board[row][col]) return false;
            for (int i = 0; i < 9; i++) if (i != row && board[i][col] == board[row][col]) return false;
            for (int i = 3*(row/3); i < 3*(row/3)+3; i++) {
                for (int j = 3*(col/3); j < 3*(col/3)+3; j++) {
                    if (i == row && j == col) continue;
                    if (board[i][j] == board[row][col]) return false;
                }
            }
            return true;
        }

        bool solve(vector<vector<char> > &board) {
            int n = 9;
            for (int i = 0; i < n; i ++) {
                for (int j = 0; j < n; j ++) {
                    if(board[i][j] == '.') {
                        for (int k = 0; k < n; k++) {
                            char c = '1' + k;
                            board[i][j] = c;
                            if (isValid(board, i, j) && solve(board)) return true;
                            board[i][j] = '.';
                        }
                        return false;
                    }
                }
            }
            return true;
        }

};
