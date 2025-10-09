class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n - 2; ++i){
            if (i != 0 && nums[i] == nums[i-1])continue;
            for (int j = i+1; j < n-1; ++j){
                if (j != i+1 && nums[j] == nums[j-1])continue;
                long t = target - (long)(nums[i] + nums[j]);
                int s = j+1, e = n - 1;
                while (s < e){
                    int sum = nums[s] + nums[e];
                    if (sum < t) s++;
                    else if (sum > t) e--;
                    else{
                        ans.push_back({nums[i], nums[j], nums[s++], nums[e--]});
                        while (s < e && nums[s] == nums[s-1])s++;
                        while (s < e && nums[e] == nums[e+1])e--;
                    }
                }
            }
        }
        return ans;
    }
};
