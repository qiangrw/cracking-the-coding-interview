class Solution {
    public:
        void sortColors(int A[], int n) {
            auto it = partition(A, A+n, [&](int x) { return x == 0; });
            partition(it, A+n, [&](int x) {return x == 1; });
        }
};
