class Solution {
public:
    void permuteHelper(vector<int>& nums, vector<vector<int>>& permutations, int i){
        if (i == nums.size()){
            permutations.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); ++j){
            swap(nums[i], nums[j]);
            permuteHelper(nums, permutations, i+1);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        permuteHelper(nums, permutations, 0);
        return permutations;
    }
};
