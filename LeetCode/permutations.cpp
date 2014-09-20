class Solution {
    public:
        vector<vector<int> > permute(vector<int> &num) {
            vector<vector<int> > res;
            if(num.empty()) return res;
            sort(num.begin(), num.end());
            do {
                res.push_back(num);
            } while(next_permutation(num.begin(), num.end()));
            return res;
        }

        template<typename BidIt>
            bool next_permutation(BidIt begin, BidIt end) {
                auto rbegin = reverse_iterator<BidIt>(end);
                auto rend = reverse_iterator<BidIt>(begin);
                auto pivot = next(rbegin);
                while (pivot != rend && *pivot >= *prev(pivot)) ++pivot;
                if (pivot == rend) {
                    reverse(rbegin, rend);
                    return false;
                } else {
                    auto p = rbegin;
                    while (*p <= *pivot) ++p;
                    swap(*p, *pivot);
                    reverse(rbegin, pivot);
                    return true;
                }
            }
};
