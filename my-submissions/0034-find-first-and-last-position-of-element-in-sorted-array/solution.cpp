class Solution {
private:
    int lower_bound(vector<int>& arr, int val) {
        // smallest index such that arr[idx] >= n

        int l = 0, r = arr.size() - 1;
        int lb = arr.size();
        while (l <= r) {
            int m = l + ((r - l) >> 2);
            int mid = arr[m];

            if (mid < val)      l = m + 1;
            else {
                lb = m;
                r = m - 1;
            }
        }
        return lb;
    }

    int upper_bound(vector<int>& arr, int val) {
        // smallest index such that arr[idx] > n

        int l = 0, r = arr.size() - 1;
        int ub = arr.size();
        while (l <= r) {
            int m = l + ((r - l) >> 2);
            int mid = arr[m];

            if (mid <= val)      l = m + 1;
            else {
                ub = m;
                r = m - 1;
            }
        }
        return ub;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int si = lower_bound(nums, target);
        if (si == nums.size() || nums[si] != target)  return {-1, -1};
        int ei = upper_bound(nums, target);
        return {si, ei - 1};
    }
};
