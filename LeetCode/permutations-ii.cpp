class Solution {
    public:
        vector<vector<int> > permuteUnique(vector<int> &num) {
            vector<vector<int> > res;
            if(num.empty()) return res;
            sort(num.begin(), num.end());
            do {
                res.push_back(num);
            } while(std::next_permutation(num.begin(), num.end()));
            return res;
        }
};
