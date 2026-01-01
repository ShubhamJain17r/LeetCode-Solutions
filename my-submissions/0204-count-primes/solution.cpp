class Solution {
public:
    int countPrimes(int n) {
        vector<bool> soe(n, false);
        for (long long i = 2; i * i < n; i++) {       // O(n log(log n))
            if (soe[i] == true) 
                continue;
            for (long long j = i * i; j < n; j += i) {
                soe[j] = true;
            }
        }

        int cnt = 0;
        for (int i = 2; i < n; ++i) {
            if (soe[i] == false) cnt++;
        }
        
        return cnt;
    }
};
