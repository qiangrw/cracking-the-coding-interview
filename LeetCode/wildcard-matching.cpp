class Solution {
    public:
        bool isMatch(const char *s, const char *p) {
            const char *str = s;
            const char *ptr = p;
            bool star = false;
            while(*str != '\0') {
                if(*ptr == '?') {
                    ++ptr;
                    ++str;
                } else if(*ptr == '*') {
                    s = str;
                    p = ptr;
                    star = true;
                    while(*p == '*') ++p;
                    if(*p == '\0') return true;
                    str = s;
                    ptr = p;
                } else if(*ptr != *str) {
                    if(!star) return false;
                    else {
                        s++;
                        str = s;
                        ptr = p;
                    }
                } else {  // *ptr == *str
                    ++ptr;
                    ++str;
                }
            }
            while(*ptr == '*') ++ptr;
            return (*ptr == '\0');
        }
};
