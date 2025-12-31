class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (const int &val : nums)
            ans ^= val;
        return ans;
    }
};
