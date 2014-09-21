class Solution {
    public:
        int romanToInt(string s) {
            // I(1) V(5) X(10) L(50) C(100) D(500) M(1000)
            const int radix[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
            const string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

            map<string, int> du_dict;
            map<string, int> si_dict;
            for (int i = 0; i < 13; ++i) {
                if (symbols[i].size() == 2) du_dict[symbols[i]] = radix[i];
                else si_dict[symbols[i]] = radix[i];
            }

            int res = 0;
            for (int i = 0; i < s.size(); ++i) {
                if (i != s.size() - 1 && du_dict.find(s.substr(i, 2)) != du_dict.end()) {
                    res += du_dict[s.substr(i,2)];
                    ++i;
                } else {
                    res += si_dict[s.substr(i,1)];
                }
            }
            return res;

        }
};
