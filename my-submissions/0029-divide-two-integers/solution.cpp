class Solution {
public:
    int divide(int dividend, int divisor) {
        long long d = abs(1LL * dividend);
        long long n = abs(1LL * divisor);

        bool negative = false;
        if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0) negative = true;

        if (dividend == 0) return 0;
        if (d == n) return negative ? -1 : 1;
        if (n > d) return 0;

        long long q = 0;
        while (d >= n) {
            int cnt = 1;
            while ((n << cnt) < d) cnt++;
            q += (1 << (cnt - 1));
            d = d - (n << (cnt - 1));
        }
        if (negative) {
            if (q > INT_MAX)
                return INT_MIN;
            return ~q + 1;
        }
        return q >= INT_MAX ? INT_MAX : q;
    }
};
