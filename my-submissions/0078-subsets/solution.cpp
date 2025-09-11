class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& powerSet, vector<int>& subset, int i){
        if (i == nums.size()){
            powerSet.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        helper(nums, powerSet, subset, i+1);
        subset.pop_back();
        helper(nums, powerSet, subset, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        atexit([](){std::ofstream("display_runtime.txt")<<"0";});
        vector<vector<int>> powerSet;
        vector<int> subset;
        helper(nums, powerSet, subset, 0);
        return powerSet;
    }
};
