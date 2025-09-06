class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int freq = 1;

        for (int i = 1; i<nums.size(); ++i){
            if (nums[i] == candidate){
                freq++;
            }
            else{
                freq--;
            }
            if (freq == -1){
                freq = 1;
                candidate = nums[i];
            }
        }
        return candidate;
    }
};
