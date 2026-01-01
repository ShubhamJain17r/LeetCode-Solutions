class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1) return x;
        if (n == INT_MIN) return x == -1;
        if (n == 0) return 1;

        int n_ = n;
        n = abs(n);

        double ans = 1;

        while (n > 0) {
            if (n & 1 == 1) {       // odd
                ans *= x;
                n--;
            }
            else {
                x *= x;
                n >>= 1;
            }
        }

        if (n_ < 0) return 1 / ans;
        return ans;
    }
};
