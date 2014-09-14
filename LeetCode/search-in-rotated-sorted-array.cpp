class Solution {
    public:
        int search(int A[], int n, int target) {
            int start = 0;
            int end = n;
            while (start < end) {
                int mid = start + (end - start) / 2;
                if (A[mid] == target) return mid;
                if (A[start] < A[mid]) {
                    if (target >= A[start] && target < A[mid]) end = mid;
                    else start = mid + 1;
                } else {
                    if (target > A[mid] && target <= A[end-1]) start = mid + 1;
                    else end = mid;
                }
            }
            return -1;
        }
};
