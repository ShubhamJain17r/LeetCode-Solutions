class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int numOp = 0;
        int last = 0;
        int n = nums.size();
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] == nums[i+1]) {}

            else {
                numOp += (n - 1 - i);
            }
        }
        return numOp;
    }
};
