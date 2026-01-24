class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        if (x % 10 == 0) return false;

        long long rev = 0;

        while (x > rev) {
            int rem = x % 10;

            rev = rev * 10 + rem;
            x = x / 10;
        }

        if (rev == x || (rev / 10) == x) return true;
        return false;
    }
};
