class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            int res = 0;
            if (prices.empty()) return 0;
            int min_price = prices[0];
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] > min_price) {
                    res += (prices[i] - min_price);
                }
                min_price = prices[i];
            }
            return res;
        }
};
