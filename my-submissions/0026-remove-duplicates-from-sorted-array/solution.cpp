class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        int curr = nums[0];
        for (int i = 1; i<nums.size(); ++i){
            if (nums[i] != curr){
                nums[k++] = nums[i];
                curr = nums[i];
            }
        }
        return k;
    }
};
