class Solution {
    public:
        string addBinary(string a, string b) {
            ostringstream oss;
            int c = 0;
            for (int i = 0; i < a.size() && i || i < b.size() || c > 0; ++i) {
                int inta = i < a.size() ? a[a.size() - i - 1] - '0' : 0;
                int intb = i < b.size() ? b[b.size() - i - 1] - '0' : 0;
                int sum = inta + intb + c;
                c = sum / 2;
                oss << sum % 2;
            }
            string res = oss.str();
            reverse(res.begin(), res.end());
            return res;
        }
};
