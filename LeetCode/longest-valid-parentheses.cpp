class Solution {
    public:
        int longestValidParentheses(string s) {
            stack<int> stk;
            int res = 0, last = -1;
            for (int i = 0; i < s.size(); ++i) {
                if(s[i] == '(') {
                    stk.push(i);
                } else {
                    if(stk.empty()) {
                        last = i;
                    } else {
                        stk.pop();
                        res = max(res, stk.empty() ? i - last : i - stk.top());
                    }
                }
            }
            return res;
        }
};
