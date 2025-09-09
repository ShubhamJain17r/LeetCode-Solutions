class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int writeIndex = 0;

        for (int curr : nums){
            if (writeIndex < 2 || curr != nums[writeIndex - 2])
                nums[writeIndex++] = curr;
        }

        return writeIndex;
    }
};
