class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        int k = 0;
        while (idx < n){
            if (nums[idx] == 0){
                idx++;
                continue;
            }
            swap(nums[idx++], nums[k++]);
        }
    }
};
