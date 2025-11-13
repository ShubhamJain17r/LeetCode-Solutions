class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr = 0, maxOnes = 0;
        int n = nums.size();
        for (int val : nums) {
            if (val == 0) {
                maxOnes = max(maxOnes, curr);
                curr = 0;
            }
            else {
                curr++;            
            }
        }
        maxOnes = max(maxOnes, curr);
        return maxOnes;
    }
};
