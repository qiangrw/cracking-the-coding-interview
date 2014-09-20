class Solution {
    public:
        int jump(int A[], int n) {
            int curlen = 1, nextlen = 0;
            int step = 0;
            int i = 0;
            while (curlen != 0) {
                while (curlen != 0) {
                    --curlen; 
                    --nextlen;
                    nextlen = max(nextlen, A[i]);
                    if (i == n - 1) return step;
                    ++i;
                }
                curlen = nextlen;
                nextlen = 0;
                ++step;
            }
            return -1;
        }
};
