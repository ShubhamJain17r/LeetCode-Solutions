class Solution {
public:
    bool isHappy(int n) {
        unordered_set<long long> hash;
        while (n != 1 && (hash.count(n) == 0)) {
            int sumOfSquare = 0;
            hash.insert(n);
            while (n > 0) {
                int rem = n % 10;
                sumOfSquare += (rem * rem);
                n /= 10;
            }
            n = sumOfSquare;
        }
        return n == 1;
    }
};
