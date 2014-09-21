class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0) return false;
            int d = 1;
            // CAUSION: avoid overflow
            while (x / d >= 10) d *= 10;

            while (x != 0) {
                int left = x / d;
                int right = x % 10;
                if (left != right) return false;
                x = (x % d) / 10;
                d /= 100;
            }
            return true;
        }
};
