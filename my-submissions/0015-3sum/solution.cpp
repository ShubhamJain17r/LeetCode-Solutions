class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        if (nums[0] > 0 || nums[n-1] < 0) return {};
        if (nums[0] == 0 && nums[n-1] == 0) return {{0,0,0}};

        vector<vector<int>> ans;

        for (int i = 0; i < n; ++i){
            if (i == 0 || nums[i-1] != nums[i]){
                int target = - nums[i];
                int s = i+1, e = n-1;
                while (s < e){
                    int sum = nums[s] + nums[e];
                    if (sum == target){
                        ans.push_back({nums[i], nums[s++], nums[e--]});
                        while (s < e && nums[s] == nums[s - 1]) s++;
                        while (s < e && nums[e] == nums[e + 1]) e--;
                    }
                    else if (sum < target) s++;
                    else e--;
                }
            }
        }
        return ans;
    }
};
