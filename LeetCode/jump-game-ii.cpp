class Solution {
    public:
        int jump(int A[], int n) {
            int cur = 0, last = 0;
            int step = 0;
            for (int i = 0; i < n; i++) {
                if (i > last) {
                    last = cur;
                    ++step;
                }
                cur = max(cur, i + A[i]);
            }
            return step;
        }

        /*int jump(int A[], int n) {
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
        }*/
};
