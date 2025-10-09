class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int curr = nums[0];

        for (int val : nums){
            if (val == curr){
                count++;
                if (count > n/2) 
                    return curr;
            }else{
                count--;
                if (count < 0){
                    curr = val;
                    count = 0;
                }
            }
        }
        return curr;
    }
};
