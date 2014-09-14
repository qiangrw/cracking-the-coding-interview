class Solution {
    public:
        bool search(int A[], int n, int target) {
            int start = 0;
            int end = n;
            while (start < end) {
                int mid = start + (end - start) / 2;
                if (A[mid] == target) return true;
                if (A[start] < A[mid]) {
                    if(A[mid] > target && A[start] <= target) end = mid;
                    else start = mid+1;
                } else if (A[start] > A[mid]){
                    if (A[mid] < target && A[end-1] >= target) start = mid+1;
                    else end = mid;
                } else {
                    start += 1;
                }
            }
            return false;
        }
};
