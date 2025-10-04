class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n-1;

        while (s<=e){
            int m = s + (e - s)/2;
            int start = nums[s], end = nums[e], mid = nums[m];

            if (mid == target) return m;
            if (start == target) return s;
            if (end == target) return e;
            if (mid < end){
                if (target > mid && target < end) s = m+1;
                else e = m-1;
            }
            else{
                if (target > start && target < mid) e =  m-1;
                else s = m+1;
            }
        }
        return -1;
    }
};
