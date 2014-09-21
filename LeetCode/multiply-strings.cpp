class Solution {
    public:
        string multiply(string num1, string num2) {
            int len1 = num1.size();
            int len2 = num2.size();
            vector<int> v1, v2;
            for(int i = len1-1; i >= 0; --i) v1.push_back(num1[i]-'0');
            for(int i = len2-1; i >= 0; --i) v2.push_back(num2[i]-'0');


            vector<int> ans(len1+len2+1, 0);
            for (int i = 0; i < len2; ++i) {
                int c = 0;
                for (int j = 0; j < len1; ++j) {
                    ans[i+j] += v2[i] * v1[j] + c;
                    c = ans[i+j] / 10;
                    ans[i+j] = ans[i+j] % 10;
                }
                if (c > 0) ans[i+len1] += c;
            }

            ostringstream res;
            bool start = true;
            for(int i=ans.size()-1; i>=0; --i) {
                if (ans[i] != 0) start = false;
                if (!start) res << ans[i];
            }
            if(start) res << 0;
            return res.str();
        }
};
