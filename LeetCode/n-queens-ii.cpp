class Solution {
    public:
        int totalNQueens(int n) {
            int res = 0;;
            if (n == 0) return res;
            vector<bool> col_visit(n, false), d1_visit(2*n+1, false), d2_visit(2*n+1, false);
            solve(n, 0, col_visit, d1_visit, d2_visit, res);
            return res;
        }

        void solve(int n, int row, vector<bool> &col_visit, vector<bool> &d1_visit, vector<bool> &d2_visit, int &res) {
            if(row == n) {
                res += 1;
                return;
            }          
            for (int col = 0; col < n; col++) {
                if (!col_visit[col] && !d1_visit[row+col] && !d2_visit[n+row-col]) {
                    col_visit[col] = d1_visit[row+col] = d2_visit[n+row-col] = true;
                    solve(n, row+1, col_visit, d1_visit, d2_visit, res);
                    col_visit[col] = d1_visit[row+col] = d2_visit[n+row-col] = false;
                }
            }
        }
};
