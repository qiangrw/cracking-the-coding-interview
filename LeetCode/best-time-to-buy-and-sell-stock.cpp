class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            if (prices.empty()) return 0;
            int res = 0, min_price = prices[0], max_price = prices[0];
            for (auto p: prices) {
                min_price = min(min_price, p);
                res = max(res, p - min_price);
            }
            return res;
        }
};
