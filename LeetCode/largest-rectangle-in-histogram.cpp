class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int res = 0;
        height.push_back(0);
        stack<int> s;
        int i = 0;
        while (i < height.size()) {
            if (s.empty() || height[i] > height[s.top()]) {
                s.push(i++);
            } else {
                int tmp = s.top();
                s.pop();
                int width = s.empty() ? i : (i - s.top() - 1);
                res = max(res, width * height[tmp]);
            }
        }
        return res;
    }
};