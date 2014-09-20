class Solution {
    public:
        string countAndSay(int n) {
            string str = "1";
            for (int i = 1; i < n; ++i) {
                char cur = str[0];
                int cnt = 1;
                ostringstream oss;
                for (int j = 1; j < str.size(); ++j) {
                    if (str[j] == cur) {
                        ++cnt;
                    } else {
                        oss << cnt << cur;
                        cur = str[j];
                        cnt = 1;
                    }
                }
                oss << cnt << cur;
                str = oss.str();
            }
            return str;
        }
};
