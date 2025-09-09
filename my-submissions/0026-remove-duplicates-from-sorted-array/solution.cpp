class Solution {
public:
    int findNextDistinct(vector<int>& nums, int idx, int curr){
        while (idx < nums.size() && nums[idx] <= curr)idx++;
        return idx;
    }
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || (n == 2 && nums[0] == nums[1])) return 1;

        int curr = nums[0];
        int idx = 1, next = 1; 

        while (idx < n && next < n){
            if (nums[idx] <= curr){
                next = findNextDistinct(nums, next, curr);
                if (next == n) return idx;
                swap(nums[idx], nums[next]);
            }
            curr = nums[idx];
            idx++;
        }
        return idx;
    }
};
