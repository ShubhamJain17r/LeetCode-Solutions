class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1){
            if (nums[0] == val){
                return 0;
            }
            else{
                return 1;
            }
        }

        int n = nums.size();
        int st = 0, ed = n - 1; 

        while (st <= ed){
            if (nums[st] == val){
                while (ed > st && nums[ed] == val)ed--;
                if (ed == st) return st;
                swap(nums[st], nums[ed--]);
            }
            st++;
        }
        return st;
    }
};
