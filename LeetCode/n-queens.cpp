class Solution {
    public:
        vector<vector<string> > solveNQueens(int n) {
            vector<vector<string> > res;
            if (n == 0) return res;
            vector<int> path;
            vector<bool> col_visit(n, false), d1_visit(2*n+1, false), d2_visit(2*n+1, false);

            solve(n, 0, col_visit, d1_visit, d2_visit, path, res);
            return res;
        }

        void solve(int n, int row, vector<bool> &col_visit, vector<bool> &d1_visit, vector<bool> &d2_visit, 
                    vector<int> &path, vector<vector<string> > &res) {
            if(row == n) {
                vector<string> spath;
                for (auto x: path) {
                    string temp(n, '.');
                    temp[x] = 'Q';
                    spath.push_back(temp);
                }
                res.push_back(spath);
                return;
            }
            for (int col = 0; col < n; ++col) {
                if (!col_visit[col] && !d1_visit[row+col] && !d2_visit[n+row-col]) {
                    col_visit[col] = d1_visit[row+col] = d2_visit[n+row-col] = true;
                    path.push_back(col);
                    solve(n, row+1, col_visit, d1_visit, d2_visit, path, res);
                    path.pop_back();
                    col_visit[col] = d1_visit[row+col] = d2_visit[n+row-col] = false;
                }
            }
        }
};
