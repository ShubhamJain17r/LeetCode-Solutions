class Solution {
public:
    int findNonZero(vector<int>& nums, int i){
        while (i < nums.size() && nums[i] == 0) i++;
        return i;
    }
    int findZero(vector<int>& nums, int i){
        while (i < nums.size() && nums[i] != 0) i++;
        return i;
    }

    void moveZeroes(vector<int>& nums) {
        int k =  findZero(nums, 0);
        int i = findNonZero(nums, 0);

        if (i == nums.size() || k == nums.size()) return;

        while (k < nums.size() && i < nums.size()){
            if (k < i){
                swap(nums[i], nums[k]);
                k = findZero(nums, k+1);
            }
                i = findNonZero(nums, i+1);
        }
    }
};
