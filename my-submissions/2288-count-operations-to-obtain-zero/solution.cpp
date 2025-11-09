class Solution {
public:
    int countOperations(int num1, int num2) {
        int total = 0;
        while (num1 && num2) {
            if (num1 > num2) {
                total += num1 / num2;
                num1 %= num2;
            }
            else {
                total += num2 / num1;
                num2 %= num1;
            }
        }
        return total;
    }
};
