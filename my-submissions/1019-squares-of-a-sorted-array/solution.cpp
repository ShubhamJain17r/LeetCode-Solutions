class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        int r = 0;
        for (; r < n; ++r) {
            if (nums[r] >= 0) break;
        }
        int l = r - 1;
        
        while (l >= 0 || r < n) {
            int ls = l >= 0 ? nums[l] * nums[l] : INT_MAX;
            int rs = r < n  ? nums[r] * nums[r] : INT_MAX;

            if (rs < ls) {
                res.push_back(rs);
                r++;
            }
            else {
                res.push_back(ls);
                l--;
            }
        }
        return res;
    }
};
