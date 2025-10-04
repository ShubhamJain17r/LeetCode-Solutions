class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        if (nums[0] >= target) return 0;
        if (nums[n-1] < target) return n;
        if (nums[n-1] == target) return n-1;

        int s = 1, e = n-2;
        while (s <= e){
            int m = s + (e-s)/2;
            if (nums[m] == target) return m;

            if (nums[m] < target){
                if (nums[m+1] > target) return m + 1;
                s = m+1;
            }
            else{
                if (nums[m-1] < target) return m;
                e = m-1;
            }
        }
        return s;
    }
};
