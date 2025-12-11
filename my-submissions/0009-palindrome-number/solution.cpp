class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x % 10 == x)
            return true;
        if (x % 10 == 0)
            return false;
        long long x2 = 0;
        while (x > x2) {
            int rem = x % 10;
            x2 = x2 * 10 + rem;
            if (x2 > INT_MAX)
                return false;
            x = x / 10;
        }
        if (x == x2 || x == x2 / 10)
            return true;
        return false;
    }
};
