class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;
        if (dividend == 0) return 0;
        bool sign = true;
        if (dividend < 0 && divisor > 0) sign = false;
        if (dividend > 0 && divisor < 0) sign = false;
        long long n = llabs(dividend), d = llabs(divisor);
        unsigned long long ans = 0;
        while (n >= d) {
            long long cnt = 0;
            while (n >= (d << (cnt + 1))) cnt++;
            ans += 1 << cnt;
            n = n - (d << cnt);
        }
        cout<<ans;
        if(ans >= INT_MAX && sign) return INT_MAX;
        if(ans > INT_MAX && !sign) return INT_MIN;
        return sign ? ans : ~ans + 1;
    }
};
