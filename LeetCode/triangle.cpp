class Solution {
    public:
        int minimumTotal(vector<vector<int> > &triangle) {
            if (triangle.empty()) return 0;
            int m = triangle.size();
            vector<int> f(m, INT_MAX);
            f[0] = 0;
            for (int i = 0; i < m; ++i) {
                for (int j = i; j >= 1; --j) {
                    f[j] = min(f[j], f[j-1]) + triangle[i][j];
                }
                f[0] = f[0] + triangle[i][0];
            }
            return *min_element(f.begin(), f.end());
        }
};
