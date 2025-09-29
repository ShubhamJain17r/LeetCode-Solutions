class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n-1;

        while (s <= e){
            int m = s + (e - s)/2;
            if (nums[m] == target){
                s = m-1, e = m + 1;
                while (s >= 0 && nums[s] == target)s--;
                while (e < n && nums[e] == target) e++;

                return vector<int> {s+1, e-1};
            }
            if (nums[m] > target)e = m-1;
            else s = m + 1;
        }
        return vector<int> {-1,-1};
    }
};
