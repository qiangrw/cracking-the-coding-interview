class Solution {
    public:
        bool isValid(string s) {
            stack<char> stk;
            unordered_map<char, int> dict;
            dict['('] = dict[')'] = 1;
            dict['['] = dict[']'] = 2;
            dict['{'] = dict['}'] = 3;

            for (int i=0; i<s.size(); i++) {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                    stk.push(s[i]);
                }  else {
                    if(stk.empty() || dict[stk.top()] != dict[s[i]]) return false;
                    stk.pop();
                }
            }
            return stk.empty();
        }
};
