class Solution {
private:
    static const int MOD = 1337;
    int modPow(int a, int k) {
        int res = 1;
        a %= MOD;
        while (k > 0) {
            if (k & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            k >>= 1;
        }
        return res;
    }
public:
    int superPow(int a, vector<int>& b) {
        int result = 1;
        a %= MOD;

        for (const int &digit : b) {
            result = modPow(result, 10);
            result = (result * modPow(a, digit)) % MOD;
        }

        return result;
    }
};
