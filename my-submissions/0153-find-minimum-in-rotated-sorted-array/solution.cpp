class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) {
            if (nums[0] < nums[1]) return nums[0];
            return nums[1];
        }
        int s = 1, e = n-2;

        while (s <= e){
            int m = s + (e-s)/2;
            int start = nums[s], end = nums[e], mid = nums[m];
            if (mid < nums[m+1] && mid < nums[m-1]) return mid;
            if (mid < end) e = m-1;
            else s = m+1;
        }
        if (nums[0] < nums[n-1]) return nums[0];
        return nums[n-1];
    }
};
