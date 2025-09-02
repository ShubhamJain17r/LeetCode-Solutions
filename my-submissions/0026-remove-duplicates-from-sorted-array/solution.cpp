class Solution {
public:
    int findNextUnique(vector<int>& nums, int curr, int idx){
        while (idx < nums.size() && nums[idx] == curr)idx++;
        return idx;
    }
    int removeDuplicates(vector<int>& nums) {
        int curr = nums[0];
        int i = findNextUnique(nums, curr, 0);

        int k = 1;

        if (i == nums.size()) return 1;

        while (i < nums.size()){
            if (nums[i] != curr){
                curr = nums[i];

                // cout<<curr<<' '<<nums[k]<<' '<<nums[i]<<' '<<k<<endl;

                // swap nums[k] <-> nums[i]
                if (i != k){
                    nums[k] ^= nums[i];
                    nums[i] ^= nums[k];
                    nums[k] ^= nums[i];
                }
                i++;
                k++;
            }
            else{
                i = findNextUnique(nums, curr, i);
            }
        }
        return k;
    }
};
