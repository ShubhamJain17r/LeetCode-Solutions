class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;

        long long Numerator = dividend;
        long long Denomenator = divisor;

        bool isDividendNeg = false;
        bool isDivisorNeg = false;

        if (dividend < 0) {
            Numerator = -Numerator;
            isDividendNeg = true;
        }
        if (divisor < 0) {
            Denomenator = -Denomenator;
            isDivisorNeg = true;
        }

        long long quot = 0;

        if (Denomenator == 1) {
            quot = Numerator;
            if (quot > INT_MAX && !(isDividendNeg ^ isDivisorNeg)) return INT_MAX;

            goto exit;
        }

        while (Numerator >= Denomenator) {
            int pow = 0;
            while ((Denomenator << pow) <= Numerator) {cout << pow << endl; pow++;}

            quot += (1 << (pow - 1));
            Numerator -= (Denomenator << (pow - 1));
        }

        exit : return ((isDividendNeg ^ isDivisorNeg)  ?
                    -quot                       : 
                    quot);
    }
};
