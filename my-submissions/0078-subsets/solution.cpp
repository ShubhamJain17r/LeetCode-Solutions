class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subsets = 1 << n;

        vector<vector<int>> res(subsets);
        for (int i = 0; i < subsets; ++i) {
            for (int bit = 0; bit < nums.size(); ++bit) {
                int num = 1 << bit;
                if (i & num)
                    res[i].push_back(nums[bit]);
            }
        }
        return res;
    }
};
