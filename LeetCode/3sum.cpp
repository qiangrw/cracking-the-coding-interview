class Solution {
    public:
        vector<vector<int> > threeSum(vector<int> &num) {
            vector<vector<int> > res;
            if (num.size() <= 2) return res;

            sort(num.begin(), num.end());
            for (auto a = num.begin(); a != prev(num.end(), 2); ++a) {
                if (a != num.begin() && *a == *prev(a)) continue;
                auto b = next(a);
                auto c = prev(num.end());
                while (b < c) {
                    if (*a + *b + *c == 0) {
                        vector<int> temp;
                        temp.push_back(*a);
                        temp.push_back(*b);
                        temp.push_back(*c);
                        res.push_back(temp);
                        b++;
                        c--;
                        while (b < c && *prev(b) == *b) ++b;
                    } else if (*a + *b + *c < 0) {
                        b++;
                    } else {
                        c--;
                    }
                }
            }
            // remvoe duplicate
            // sort(res.begin(), res.end());
            // res.erase(unique(res.begin(), res.end()), res.end());
            return res;
        }
};
