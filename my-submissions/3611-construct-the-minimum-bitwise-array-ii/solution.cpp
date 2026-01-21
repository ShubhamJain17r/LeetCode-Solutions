class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            if ((val & 1) == 0) continue;
            if (((val + 1) & val) == 0) {
                ans[i] = (val >> 1);
            } 
            else {
                int cnt = 0;
                while (val & 1 == 1) {
                    val >>= 1;
                    cnt++;
                }
                ans[i] = nums[i] & ~(1 << (cnt - 1)); 
            }
        }
        return ans;
    }
};
