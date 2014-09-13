class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if (n == 0) return {0};
        res = {0, 1};
        int x = 1;
        for (int i = 2; i <= n; ++i) {
            x *= 2;
            for (int j = res.size() - 1; j >= 0; --j) {
                res.push_back(res[j] + x);
            }
        }
        return res;
    }
};