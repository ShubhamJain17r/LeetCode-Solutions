class Solution {
public:
    void permutations(vector<int> &nums, vector<vector<int>> &res, int idx) {
        if (idx == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); ++i) {
            swap(nums[i], nums[idx]);
            permutations(nums, res, idx + 1);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int idx = 0;
        vector<vector<int>> res;
        permutations(nums, res, idx);
        return res;
    }
};
