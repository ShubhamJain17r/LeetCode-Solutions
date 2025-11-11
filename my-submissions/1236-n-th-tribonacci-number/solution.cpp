class Solution {
public:
    int tribonacci(int n) {
        if (n == 0 || n == 1) return n;
        if (n == 2) return 1;
        vector<int> fibo(n+1, 0);
        fibo[0] = 0, fibo[1] = 1, fibo[2] = 1;
        for (int i = 3; i <= n; i++) {
            fibo[i] = fibo[i-1] + fibo[i-2] + fibo[i-3];
        }
        return fibo[n];
    }
};
