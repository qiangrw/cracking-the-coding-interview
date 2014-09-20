class Solution {
    public:
        int removeElement(int A[], int n, int elem) {
            int j = 0;
            for (int i = 0; i < n; ++i) {
                if (A[i] == elem) continue;
                A[j++] = A[i];
            }
            return j;
        }
};
