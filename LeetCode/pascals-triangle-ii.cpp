class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector<int> f = {1};
            for (int i = 1; i <= rowIndex; ++i) {
                for (int j = i - 1; j > 0; --j) {
                    f[j] = f[j] + f[j-1];
                }
                f.push_back(1);     // f[i]
            }
            return f;
        }
};
