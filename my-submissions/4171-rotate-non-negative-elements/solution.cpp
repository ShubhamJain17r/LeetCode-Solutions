class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> positive;

        for (int i = 0; i < n; ++i) {
            if (nums[i] >= 0) {
                positive.push_back(nums[i]);
            }
        }

        if (positive.size() == 0) return nums;
        k = k % positive.size();
        if (k == 0) return nums;

        reverse(positive.begin(), positive.begin() + k);
        reverse(positive.begin() + k, positive.end());
        reverse(positive.begin(), positive.end());

        vector<int> ans(n);

        int idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                ans[i] = nums[i];
            }
            else {
                ans[i] = positive[idx];
                idx++;
            }
        }

        return ans;
    }
};
