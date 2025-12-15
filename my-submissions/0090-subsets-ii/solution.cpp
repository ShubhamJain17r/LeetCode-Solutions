class Solution {
public:
    void f(int idx, vector<int>& nums, vector<vector<int>> &subsets, vector<int> &subset) {
        subsets.push_back(subset);
        for (int i = idx; i < nums.size(); i++) {
            if (i != idx && nums[i] == nums[i - 1]) continue;
            subset.push_back(nums[i]);
            f(i + 1, nums, subsets, subset);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<vector<int>> subsets;
        f(0, nums, subsets, subset);
        return subsets;
    }
};
