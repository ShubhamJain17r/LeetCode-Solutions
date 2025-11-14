class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> points(maxVal + 1, 0);
        for (int val : nums) {
            points[val]+= val;
        }
        int prev2 = 0;
        int prev1 = points[1];
        for (int i = 2; i<= maxVal; ++i) {
            int curr = max(prev1, prev2 + points[i]);
            prev2 = prev1;
            prev1 = curr; 
        }
        return prev1;
    }
};
