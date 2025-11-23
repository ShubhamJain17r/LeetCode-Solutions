class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            if (m.count(nums[i])) {
                return {m[nums[i]], i};
            }
            else {
                m[target - nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};
