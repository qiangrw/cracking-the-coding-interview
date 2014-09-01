class Solution {
public:
    bool isoperator(const string &x) {
        return x == "+" || x == "-" || x == "*" || x == "/";
    }
    
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        int res = 0;
        if (tokens.empty()) return 0;
        for (auto x: tokens) {
            if (isoperator(x)) {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                if (x == "+") s.push(a + b);
                else if(x == "-") s.push(a - b);
                else if(x == "*") s.push(a * b);
                else if(x == "/") s.push(a / b);
            } else {
                s.push(atoi(x.c_str()));
            }
        }
        return s.top();
    }
};