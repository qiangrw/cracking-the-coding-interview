class Solution {
    public:
        int maxArea(vector<int> &height) {
            int start = 0;
            int end = height.size() - 1;
            int res = 0;
            while (start < end) {
                res = max(res, min(height[start], height[end]) * (end-start));
                if (height[start] < height[end]) {
                    ++start;
                } else {
                    --end;
                }
            }
            return res;
        }
};
