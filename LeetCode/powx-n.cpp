class Solution {
    public:
        double pow(double x, int n) {
            if (x == 1) return 1;
            if (x == -1) return (n % 2 == 0) ? 1 : -1;
            if(n == 0) return 1.0;

            if(n < 0) return 1.0 / pow(x, -n);
            double part = pow(x, n/2);
            return (n % 2 == 0) ? part*part : part*part*x;
        }
};
