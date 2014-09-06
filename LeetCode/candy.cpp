class Solution {
    public:
        int candy(vector<int> &ratings) {
            if (ratings.empty()) return 0;
            int n = ratings.size();
            vector<int> score(n, 1);
            int pre = 1;
            for (int i = 1; i < n; ++i) {
                if (ratings[i] > ratings[i-1]) {
                    pre += 1;
                    score[i] = pre;
                } else {
                    pre = 1; 
                }
            }
            for (int i = n-2; i >= 0; --i) {
                if (ratings[i] > ratings[i+1]) {
                    pre += 1;
                    score[i] = max(score[i], pre);
                } else {
                    pre = 1;
                }
            }
            return accumulate(score.begin(), score.end(), 0);
        }

};
