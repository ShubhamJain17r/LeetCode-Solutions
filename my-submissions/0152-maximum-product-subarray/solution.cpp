class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Step 1: Initialize
        int maxProd = nums[0];  // maximum product ending here
        int minProd = nums[0];  // minimum product ending here
        int ans = nums[0];      // global answer

        // Step 2: Iterate through array
        for (int i = 1; i < nums.size(); ++i) {
            int curr = nums[i];

            // If current number is negative, swap them
            // because multiplying by a negative flips sign
            if (curr < 0)
                swap(maxProd, minProd);

            // Step 3: Update local max and min products
            maxProd = max(curr, maxProd * curr);
            minProd = min(curr, minProd * curr);

            // Step 4: Update global maximum
            ans = max(ans, maxProd);
        }

        return ans;
    }
};
