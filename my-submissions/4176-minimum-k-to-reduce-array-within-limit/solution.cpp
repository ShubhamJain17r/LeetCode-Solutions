class Solution {
public:
    bool nonPositive(vector<int>& nums, long long k) {
        int t = 0;
        for (int &val : nums) {
            t += val / k;
            if (val % k != 0)
                t++;
            if (t > k * k) return false;
        }
        return t <= k * k;
    }
    int minimumK(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for (int &val : nums) {
            maxi = max(maxi, val);
        }

        int l = 1, h = max(maxi, n);
        int k = h;

        while (l <= h) {
            long long m = l + ((h - l) >> 1);

            if (nonPositive(nums, m)) {
                k = m;
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }

        return k;
    }
};
