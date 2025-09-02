class Solution {
public:

    int findValidElement(vector<int>& nums, int val, int i, int j){
        while (j >= i && nums[j] == val) j--;
        return j;
    }
    
    int removeElement(vector<int>& nums, int val) {
        // if (nums.size() == 1 && nums[0] == val) return 0;
        int i = 0, j = nums.size() - 1;
        j = findValidElement(nums, val, i, j);
        if (j == -1) return 0;
        int k = 0;
        while (i <= j){
            if (nums[i] == val){
                // swap nums[i] <-> nums[j]
                nums[i]^=nums[j];
                nums[j]^=nums[i];
                nums[i]^=nums[j];
                j--;
            }
            j = findValidElement(nums, val, i, j);
            i++;
            k++;
        }
        // cout<<k<<endl;
        return k;
    }
};
