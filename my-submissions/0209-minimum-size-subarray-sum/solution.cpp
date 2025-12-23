class Solution {
public:
bool enough(int target, vector<int>& nums, int k) {
    long long sum = 0;
    for (int i = 0; i < k; ++i)
        sum += nums[i];
    if (sum >= target) return true;
    for (int r = k; r < nums.size(); ++r) {
        sum += nums[r];
        sum -= nums[r - k];
        if (sum >= target) return true;
    }
    return false;
}

// O(n logn)
int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int l = 1, r = n;
    int minLen = INT_MAX;
    while (l <= r) {
        int m = l + ((r - l) >> 1);         // subarray size
        if (enough(target, nums, m)) {
            minLen = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return minLen != INT_MAX ? minLen : 0;
}
};
