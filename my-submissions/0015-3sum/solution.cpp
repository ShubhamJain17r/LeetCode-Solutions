class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) break;
            if (i == 0 || nums[i] != nums[i-1]) {
                int target = -nums[i];
                int st = i + 1, ed = n - 1;
                while (st < ed) {
                    int sum = nums[st] + nums[ed];
                    if (sum == target) {
                        res.push_back({nums[i], nums[st], nums[ed]});
                        st++, ed--;
                        while (st < ed && nums[st] == nums[st-1]) st++;
                        while (st < ed && nums[ed] == nums[ed+1]) ed--;
                    }
                    else if (sum < target) st++;
                    else ed--;
                }
            }
        }
        return res;
    }
};
