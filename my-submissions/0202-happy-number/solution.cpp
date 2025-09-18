class Solution {
public:
    int squareSumOfDigits(int n){
        int ans = 0;
        while (n > 0){
            ans = ans + (n % 10)*(n % 10);
            n = n / 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_set<int> s;
        while (n!=1 && s.find(n) == s.end()){
            s.insert(n);
            n = squareSumOfDigits(n);
        }
        return n == 1;
    }
};
