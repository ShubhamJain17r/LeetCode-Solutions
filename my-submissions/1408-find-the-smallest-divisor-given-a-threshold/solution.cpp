class Solution {
public:
int divisorSum(vector<int> &nums, int divisor) {
    int sum = 0;
    for (const int &num : nums)
        sum += static_cast<int>(ceil(num / static_cast<double>(divisor)));
    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int l = 1, r = *max_element(nums.begin(), nums.end());
    while (l <= r) {
        int m = l + ((r - l) >> 1);
        if (divisorSum(nums, m) > threshold) l = m + 1;
        else                                 r = m - 1;
    }
    return l;
}
};
