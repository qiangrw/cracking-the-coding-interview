class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
            if (obstacleGrid.empty()) return 0;
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();

            vector<int> f(n, 0);
            f[0] = obstacleGrid[0][0] ? 0 : 1;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    f[j] = obstacleGrid[i][j] ? 0 : (f[j] + (j == 0 ? 0 : f[j-1]));
                }
            }
            return f[n-1];
        }
};
