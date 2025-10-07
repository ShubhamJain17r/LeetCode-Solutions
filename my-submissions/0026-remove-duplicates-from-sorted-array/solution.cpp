class Solution {
public:
    int removeDuplicates(vector<int>& nums){
    int n = nums.size();
    int k = 0;

    for (int val : nums){
        if (k == 0 || nums[k-1] != val)
            nums[k++] = val;
    }
    return k;
}
};
