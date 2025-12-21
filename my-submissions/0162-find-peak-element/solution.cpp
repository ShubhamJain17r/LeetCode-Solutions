class Solution {
public:
int findPeakElement(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) return 0;
    if (nums[0] > nums[1]) return 0;                // as nums[-1] == INT_MIN
    if (nums[n - 2] < nums[n - 1]) return n - 1;    // as nums[n] == INT_MIN

    int l = 1, r = n - 2;

    while (l <= r) {
        int m = l + ((r - l) >> 2);
        int mid = nums[m];
        if (nums[m - 1] < mid && mid > nums[m + 1])         return m;
        if (nums[m - 1] < nums[m] && nums[m] < nums[m + 1]) l = m + 1;
        else                                                r = m - 1;
    }
    return -1;  // never executed
}
};
