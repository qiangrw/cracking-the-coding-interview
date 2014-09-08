class Solution {
    public:
        vector<vector<int> > generate(int numRows) {
            vector<vector<int> > res;
            if (numRows == 0) return res;
            res.push_back({1});
            vector<int> f = {1};
            for (int i = 1; i < numRows; ++i) {
                for (int j = i - 1; j > 0; --j) {
                    f[j] = f[j] + f[j-1];
                }
                f.push_back(1);     // f[i]
                res.push_back(f);
            }
            return res;
        }
}
