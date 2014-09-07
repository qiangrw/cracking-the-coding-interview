class Solution {
public:
    bool isPalindrome(string s) {
        auto start = s.begin(), end = s.end() - 1;
        while (start < end) {
            while (!isalnum(*start) && start < end) ++start;
            while (!isalnum(*end) && start < end) --end;
            if (start == end) return true;
            if (tolower(*start) != tolower(*end)) return false;
            ++start;
            --end;
        }
        return true;
    }
};