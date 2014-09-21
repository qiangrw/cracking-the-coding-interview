class Solution {
    public:
        int atoi(const char *str) {
            while (*str == ' ') ++ str;
            bool neg = false;
            if (*str == '+' || *str == '-') {
                neg = *str == '-';
                ++str;
            } 
            int res = 0;
            while (*str != '\0') {
                if (!isdigit(*str)) break;
                int digit = (*str - '0');
                if (res > INT_MAX / 10 || res == INT_MAX / 10 && digit> INT_MAX % 10) {
                    return neg ? INT_MIN : INT_MAX;
                }
                res = res * 10 + digit;
                ++str;
            }
            return neg ? -res : res;
        }
};
