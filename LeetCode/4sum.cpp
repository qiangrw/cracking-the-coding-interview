class Solution {
    public:
        vector<vector<int> > fourSum(vector<int> &num, int target) {
            vector<vector<int> > res;
            if (num.size() <= 3) return res;
            sort(num.begin(), num.end());
            auto last = num.end();
            for (auto a = num.begin(); a < prev(last, 3); ++a) {
                if (a != num.begin() && *a == *prev(a)) continue;
                for (auto b = a + 1; b < prev(last, 2); ++b) {
                    if (b != a + 1 && *b == *prev(b)) continue;
                    auto c = next(b, 1);
                    auto d = prev(last, 1);
                    while (c < d) {
                        if (*a + *b + *c + *d == target) {
                            res.push_back({*a, *b, *c, *d});
                            ++c;
                            --d;
                            while (c < d && *c == *prev(c)) ++c;
                        } else if (*a + *b + *c + *d < target) {
                            ++c;
                        } else {
                            --d;
                        }
                    }
                }
            }
            // remove duplicate
            // sort(res.begin(), res.end());
            // res.erase(unique(res.begin(),res.end()), res.end());
            return res;
        }
};
