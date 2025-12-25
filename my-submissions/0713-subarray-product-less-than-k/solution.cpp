class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt = 0;
        int l = 0;
        long long prod = 1;
        for (int r = 0; r < nums.size(); ++r) {
            prod *= nums[r];
            while (l <= r && prod >= k) {
                prod /= nums[l];
                l++;
            }
            if (prod < k) {
                cnt += (r - l + 1);
            }
            // cout<<r<<" "<<cnt<<endl;
        }
        return cnt;
    }
};
