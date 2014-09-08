class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            int n = prices.size();
            if(n <= 1) return 0;
            vector<int> f(n, 0), b(n, 0);
            int cur_min = prices[0];
            int max_gap = 0;
            for (int i = 1; i < n; ++i) {
                cur_min = min(cur_min, prices[i]);
                max_gap = max(max_gap, prices[i] - cur_min);
                f[i] = max_gap;
            }
            int cur_max = prices[n-1];
            max_gap = 0;
            for (int i = n-2; i >= 0; --i) {
                cur_max = max(cur_max, prices[i]);
                max_gap = max(max_gap, cur_max - prices[i]);
                b[i] = max_gap;
            }

            int res = 0;
            for (int i = 0; i < n; ++i) {
                res = max(res, f[i] + b[i]);
            }
            return res;
        }
};
