class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int best = nums[0] + nums[1] + nums[2]; // initial guess

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                // update closest sum
                if (abs(sum - target) < abs(best - target)) {
                    best = sum;
                }

                if (sum < target) {
                    l++;    // need larger sum
                } else if (sum > target) {
                    r--;    // need smaller sum
                } else {
                    return sum; // exact match
                }
            }
        }
        return best;
    }
};

