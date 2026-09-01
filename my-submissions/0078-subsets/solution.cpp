class Solution {
public:
    void f(const vector<int> &nums, vector<int> &subset, vector<vector<int>> &subsets, int idx) {
        subsets.push_back(subset);
        for (int i = idx; i < nums.size(); ++i) {
            subset.push_back(nums[i]);
            f(nums, subset, subsets, i + 1);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> subsets;

        f(nums, subset, subsets, 0);

        return subsets;        
    }
};
