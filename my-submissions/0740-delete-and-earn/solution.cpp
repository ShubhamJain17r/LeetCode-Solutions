class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> points(maxVal + 1, 0);

        for (int &x : nums)
            points[x] += x;

        // House Robber DP
        int prev2 = 0, prev1 = points[0];
        for (int i = 1; i <= maxVal; i++) {
            int pick = points[i] + prev2;
            int notPick = prev1;
            int curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

