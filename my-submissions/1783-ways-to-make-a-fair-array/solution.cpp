class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();

        long long rightEven = 0, rightOdd = 0;
        long long leftEven = 0, leftOdd = 0;

        // Precompute right side sums
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) rightEven += nums[i];
            else            rightOdd  += nums[i];
        }

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            // Remove nums[i] → subtract it from right side
            if (i % 2 == 0) rightEven -= nums[i];
            else            rightOdd  -= nums[i];

            // After removing i:
            // Left side keeps its parity
            // Right side swaps parity
            if (leftEven + rightOdd == leftOdd + rightEven)
                ans++;

            // Move nums[i] → left side for next iteration
            if (i % 2 == 0) leftEven += nums[i];
            else            leftOdd  += nums[i];
        }

        return ans;
    }
};

