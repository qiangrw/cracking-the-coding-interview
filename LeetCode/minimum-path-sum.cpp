class Solution {
    public:
        int minPathSum(vector<vector<int> > &grid) {
            if (grid.empty()) return 0;
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<int> > E(m, vector<int>(n, 0));
            for (int i = 1; i < m; ++i) E[i][0] = E[i-1][0] + grid[i-1][0];
            for (int j = 1; j < n; ++j) E[0][j] = E[0][j-1] + grid[0][j-1];
            for (int i = 1; i < m; ++i) {
                for(int j = 1; j < n; ++j) {
                    E[i][j] = min(E[i-1][j] + grid[i-1][j], E[i][j-1] + grid[i][j-1]);
                }
            }
            return E[m-1][n-1] + grid[m-1][n-1];
        }
};
