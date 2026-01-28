class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr = nums[0];
        int cnt = 1;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] == curr) {
                cnt++;
                if (cnt > (n >> 1)) return curr;
            }
            else {
                cnt--;
                if (cnt < 0) {
                    curr = nums[i];
                    cnt = 1;
                }
            }
        }
        return curr;
    }
};
