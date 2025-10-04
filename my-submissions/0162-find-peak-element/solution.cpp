class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        
        int s = 1, e = n-2;

        while (s <= e){
            int m = s + (e-s)/2;
            int mid = nums[m];

            if (nums[m-1] < mid && nums[m+1] < mid) return m;

            if (nums[m-1] < mid && nums[m+1] > mid) s = m+1;
            else e = m-1;
        }
        if (nums[0] > nums[n-1]) return 0;
        return n-1;
    }
};
