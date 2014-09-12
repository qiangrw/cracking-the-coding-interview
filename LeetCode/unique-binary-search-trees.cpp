class Solution {
    public:
        int numTrees(int n) {
            vector<int> f(n+1, 0);
            f[0] = 1;
            for(int i=1; i<=n; i++) {
                for(int k=0; k<i; k++) {
                    f[i]  += (f[k] * f[i-k-1]);
                }
            }
            return f[n];
        }
};
