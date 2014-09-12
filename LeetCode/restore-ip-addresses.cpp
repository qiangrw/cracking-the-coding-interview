class Solution {
    public:
        vector<string> restoreIpAddresses(string s) {
            vector<string> res;
            string path;
            gen(res, path, s, 0, 0);
            return res;
        }

        void gen(vector<string> &res, string path, string &s, int start, int level) {
            if (level == 4 && start == s.size()) {
                path.erase(path.end() - 1);
                res.push_back(path);
                return;
            }
            if (s.size() - start > (4-level)*3) return;
            if (s.size() - start < (4-level)) return;
            for (int len = 1; len <= 3 && start + len <= s.size(); ++len) {
                string seg = s.substr(start, len);
                if((seg.size() >= 2 && seg[0] == '0') || atoi(seg.c_str()) > 255) continue;
                gen(res, path + seg + ".", s, start + len, level + 1);
            }
        }
};
