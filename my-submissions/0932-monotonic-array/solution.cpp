class Solution {
public:
    bool decreasing(vector<int>& nums){
            cout<<"decreasing"<<endl;
        for (int i = 0; i<nums.size() - 1; ++i){
            if ((nums[i+1] - nums[i]) > 0)return false;
        }
        return true;
    }
    bool increasing(vector<int>& nums){
        cout<<"increasing"<<endl;
        for (int i = 0; i<nums.size() - 1; ++i){
            if ((nums[i+1] - nums[i]) < 0)return false;
        }
        return true;
    }
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() == 1 || nums.size() == 2) return true;

        int i = 0;
        while (i < nums.size() - 1 && nums[i] == nums[i+1])i++;
        if (i == nums.size() - 1) return true;

        if ((nums[i+1] - nums[i]) > 0)return increasing(nums);
        return decreasing(nums);
    }
};
