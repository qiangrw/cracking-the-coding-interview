class Solution {
    public:
        int lengthOfLastWord(const char *s) {
            int wordlen = 0;
            int i = strlen(s) - 1;
            while (i >= 0 && s[i] == ' ')  --i;
            while (i >= 0 && s[i] != ' ') {
                --i;
                ++wordlen;
            }
            return wordlen;
        }
};
