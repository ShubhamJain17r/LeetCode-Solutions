class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n - 1;
        for (int m = 0; m <= h; ++m){
            if (nums[m] == 0){
                swap(nums[m], nums[l]);
                l++;
            }
            else if (nums[m] == 1){}
            else {
                swap(nums[h], nums[m]);
                h--;
                m--;
            }
        } 
    }
};
