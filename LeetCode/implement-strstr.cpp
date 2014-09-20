class Solution {
    public:
        bool compare(char *a, char *b, int n) {
            for (int i = 0; i < n; ++i) if (a[i] != b[i]) return false;
            return true;
        }

        char *strStr(char *haystack, char *needle) {
            size_t len = strlen(haystack);
            size_t nlen = strlen(needle);
            if (nlen == 0) return haystack;
            if (nlen > len) return nullptr;
            if (nlen == len) return compare(haystack, needle, len) ? haystack : nullptr;
            for (unsigned int i = 0; i <= len - nlen ; ++i) {
                char *cur = haystack + i;
                if (compare(cur, needle, nlen)) return cur;
            }
            return nullptr;
        }
};
