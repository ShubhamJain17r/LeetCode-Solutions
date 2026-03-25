class Solution {
private:
    int count = 0;
public:
    void permutations(vector<int> nums, int idx, vector<vector<int>>&res) {
        if (idx == nums.size()) {
            count++;
            res.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); ++i) {
            if (i != idx && nums[i] == nums[idx]) continue;
            swap(nums[i], nums[idx]);
            permutations(nums, idx + 1, res);
            // swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        permutations(nums, 0, res);
        cout << count;
        return res;
    }
};

