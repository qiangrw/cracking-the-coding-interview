class Solution {
    public:
        bool isValidSudoku(vector<vector<char> > &board) {
            vector<bool> used(9);
            for (int i = 0; i < 9; ++i) {
                fill(used.begin(), used.end(), false);
                for (int j = 0; j < 9; ++j) {
                    char x = board[i][j];
                    if (x == '.') continue;
                    if (used[x-'1']) return false;
                    used[x-'1'] = true;
                }
                fill(used.begin(), used.end(), false);
                for (int j = 0; j < 9; ++j) {
                    char x = board[j][i];
                    if (x == '.') continue;
                    if (used[x-'1']) return false;
                    used[x-'1'] = true;
                }
            }

            for (int r = 0; r < 3; ++r) {
                for (int c = 0; c < 3; ++c) {
                    fill(used.begin(), used.end(), false);
                    for (int i = r*3; i < r*3+3; ++i) {
                        for (int j = c*3; j < c*3+3; ++j) {
                            char x = board[i][j];
                            if (x == '.') continue;
                            if (used[x-'1']) return false;
                            used[x-'1'] = true;
                        }
                    }
                }
            }

            return true;
        }
};
