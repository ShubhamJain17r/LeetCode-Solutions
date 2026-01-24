class Solution {
public:
    int trailingZeroes(int n) {
        int cntFive = 0;

        for (int i = 5; i <= n; i += 5) {
            int x = i;
            while (x % 5 == 0) {
                cntFive++;
                x = x / 5;
            }
        }

        return cntFive;
    }
};
