class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0,  r = n - 1;
    while (l < r) {
        int sum = nums[l] + nums[r];
        if (sum == target) return {l + 1, r + 1};
        if (sum < target) {
            l++;
            while (l < r && nums[l] == nums[l - 1]) l++;
        }
        else {
            r--;
            while (l < r && nums[r] == nums[r + 1]) r--;
        }
    }
    return {-1, -1};
}
};
