class Solution {
    public:
        int threeSumClosest(vector<int> &num, int target) {
            int res = INT_MAX;
            if (num.size() < 3) return res;
            sort(num.begin(), num.end());

            int min_gap = INT_MAX;
            for (auto a = num.begin(); a < prev(num.end(), 2); ++a) {
                if (a != num.begin() && *a == *prev(a)) continue;
                auto b = a + 1;
                auto c = num.end() - 1;
                while (b < c) {
                    int sum = *a + *b + *c;
                    int gap = abs(sum - target);
                    if (gap < min_gap) {
                        min_gap = gap;
                        res = sum;
                        if (min_gap == 0) return res;
                    }
                    if (sum < target) ++b;
                    else --c;
                }
            }
            return res;
        }
};
