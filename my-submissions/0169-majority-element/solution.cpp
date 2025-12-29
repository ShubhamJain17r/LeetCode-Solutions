class Solution {
public:
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    int currElement = nums[0];
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (nums[i] == currElement) {
            cnt++;
            if (cnt > (n / 2))
                return currElement;
        }
        else {
            cnt--;
            if (cnt == 0) {
                currElement = nums[i];
                cnt = 1;
            }
        }
    }
    return currElement;
}
};
