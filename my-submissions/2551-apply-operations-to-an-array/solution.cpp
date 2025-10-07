class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i){
            if (nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }    
        }
        int k = 0;
        for (int val : nums)
            if (val != 0)
                nums[k++] = val;
        for (int i = k; i < n; ++i)
            nums[i] = 0;
        return nums;
    }
};
