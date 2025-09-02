class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int idx = digits.size() - 1;
        while (idx >=0 && digits[idx] == 9){
            digits[idx] = 0;
            idx--;
        }
        if (idx != -1){
            digits[idx]++;
            return digits;
        }
        vector<int> ans(digits.size() + 1, 0);
        ans[0] = 1;
        return ans;
    }
};
