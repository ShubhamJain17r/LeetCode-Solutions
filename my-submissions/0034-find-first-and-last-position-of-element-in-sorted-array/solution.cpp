class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;

        while (s <= e){
            int m = s + (e - s) / 2;

            if (nums[m] == target){
                s = m - 1, e = m + 1;
                while (s >= 0 && nums[s] == nums[s + 1]) s--;
                while (e < nums.size() && nums[e] == nums[e - 1]) e++;

                return {s + 1, e - 1};
            }
            else if (nums[m] < target)
                s = m + 1;
            else 
                e = m - 1;
        }

        return {-1,-1};
    }
};
