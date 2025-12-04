class Solution {
public:

    int uniquePaths(int m, int n) {
        long long result = 1;
        int total = m + n - 2;
        int r = m - 1;     // choose (m-1) down steps

        for (int i = 1; i <= r; i++) {
            result = result * (total - r + i) / i;
        }
        return result;
    }
};
