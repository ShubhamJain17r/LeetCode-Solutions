class Solution {
public:
    void subsetsHelper(vector<int>& nums, vector<int>& set, vector<vector<int>>& powerSet, int i){
        if (i == nums.size()){
            powerSet.push_back(set);
            return;
        }
        set.push_back(nums[i]);
        subsetsHelper(nums, set, powerSet, i+1);
        set.pop_back();
        subsetsHelper(nums, set, powerSet, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerSet;
        vector<int> set;
        subsetsHelper(nums, set, powerSet, 0);
        return powerSet; 
    }
};
