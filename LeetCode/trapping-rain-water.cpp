class Solution {
    public:
        int trap(int A[], int n) {
            int cur_max = 0;
            int left[n], right[n];
            for (int i = 0; i < n; i++) {
                left[i] = cur_max;
                cur_max = max(A[i], cur_max);
            }
            cur_max = 0;
            for (int i = n-1; i >= 0; i--) {
                right[i] = cur_max;
                cur_max = max(A[i], cur_max);
            }
            int sum = 0;
            for (int i = 0; i < n-1; i++) {
                sum += max(0, min(left[i], right[i]) - A[i]);
            }
            return sum;
        }
};
