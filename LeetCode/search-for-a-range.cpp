class Solution {
    public:
        vector<int> searchRange(int A[], int n, int target) {
            int lower = lower_bound(A, n, target);
            int upper = upper_bound(A, n, target);
            return {lower, upper};
        }

        int lower_bound(int A[], int n, int target) {
            int start = 0;
            int end = n;
            int res = -1;
            while (start < end) {
                int mid = start + (end - start) / 2;
                if (A[mid] == target) {
                    res = mid;
                    end = mid;
                } else if (A[mid] < target) start = mid + 1;
                else end = mid;
            }
            return res;
        }

        int upper_bound(int A[], int n, int target) {
            int start = 0;
            int end = n;
            int res = -1;
            while (start < end) {
                int mid = start + (end - start) / 2;
                if (A[mid] == target) {
                    res = mid;
                    start = mid + 1;
                } else if (A[mid] < target) start = mid + 1;
                else end = mid;
            }
            return res;
        }
};
