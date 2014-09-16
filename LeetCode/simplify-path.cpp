class Solution {
    public:
        string simplifyPath(string path) {
            stack<string> s;
            string cur;
            for (int i = 0; i <= path.size(); ++i) {
                if (i == path.size() || path[i] == '/') {
                    if (cur.size() == 0 || cur == ".") {
                        cur = "";
                        continue;
                    } else if (cur == "..") {
                        if(!s.empty()) s.pop();
                    } else {
                        s.push(cur);
                    }
                    cur = "";
                } else {
                    cur += path[i];
                }
            }
            if (s.empty()) return "/";
            string res = "";
            while (!s.empty()) {
                res = "/" + s.top() + res;
                s.pop();
            }
            return res;
        }
};
