lass Solution {
    public:
        bool isNumber(const char *s) {
            int len = strlen(s);
            if (len == 0) return false;
            while (*s == ' ') ++s;

            int dotCount = 0, expCount = 0;
            // define some tags, start of number, exp tag occured, need for number input
            bool start = true, preExp = false, hasNum = false;
            while(*s != '\0') {
                if (*s == ' ') break;
                if (*s == '+' || *s == '-') {
                    if (!start && !preExp) return false;
                } else if (isdigit(*s)) {
                    hasNum = true;
                    preExp = false;
                } else if (*s == '.') {
                    dotCount += 1; 
                    preExp = false;
                    if(expCount >= 1) return false;
                } else if(*s == 'e' || *s == 'E') {
                    if (!hasNum) return false;
                    expCount += 1; 
                    hasNum = false; 
                    preExp = true;
                } else return false;

                start = false;
                if(dotCount > 1 || expCount > 1) return false;
                ++s;
            }

            if (!hasNum) return false;
            while(*s == ' ') ++s;
            return *s == '\0';
        }
};
