class Solution {
public:
bool enough(vector<int>& nums, int k, int subArrraySum) {
    int sum = 0;
    int K = 1;
    for (const int &val : nums) {
        sum += val;
        if (sum > subArrraySum) {
            K++;
            sum = val;
        }
    }
    return K <= k;
}

int splitArray(vector<int>& nums, int k) {
    int l = *max_element(nums.begin(), nums.end());
    int r = l * 2;
    while (!enough(nums, k, r)) r = r * 2;
    while (l <= r) {
        int m = l + ((r - l) >> 2);
        if (enough(nums, k, m)) r = m - 1;
        else                    l = m + 1;
    }
    return l;
}
};
