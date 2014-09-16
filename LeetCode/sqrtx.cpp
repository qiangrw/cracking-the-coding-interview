class Solution {
    public:
        int sqrt(int x) {
            if (x <= 1) return x;
            int start = 1, end = x;
            int res = 1;
            while (start < end) {
                int mid = start + (end - start) / 2;
                if (mid == x / mid) {
                    return mid;
                } else if(mid < x/mid) {
                    start = mid + 1;
                    res = mid;
                } else {
                    end = mid;
                }
            }
            return res;
        }
};
