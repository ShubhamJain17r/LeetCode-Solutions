class Solution {
public:
int findMin(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    int mini = INT_MAX;
    while (l <= r) {
        int m = l + ((r - l) >> 2);
        int mid = nums[m];

        // whole range is sorted
        if (nums[l] <= nums[r]) {
            mini = min(mini, nums[l]);
            return mini;
        }

        // left half is sorted
        if (mid >= nums[l]) {
            mini = min(mini, nums[l]);
            l = m + 1;
        }
        else {
            mini = min(mini, nums[m]);
            r = m - 1;
        }
    }
    return mini;
}
};
