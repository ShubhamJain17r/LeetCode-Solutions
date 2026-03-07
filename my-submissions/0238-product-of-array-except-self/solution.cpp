class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixProd(n, 1);
        for (int i = 1; i < n; ++i) {
            prefixProd[i] = prefixProd[i - 1] * nums[i - 1];
        }
        // [1, 1, 2, 6]
        int prod = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            prefixProd[i] *= prod; 
            prod *= nums[i]; 
        }
        // [24, 12, 8, 4]
        return prefixProd;
    }
};
