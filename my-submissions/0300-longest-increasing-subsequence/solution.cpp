class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        for (int& num : nums) {
            int i = lower_bound(arr.begin(), arr.end(), num) - arr.begin();
            if (i == arr.size())
                arr.push_back(num);
            else
                arr[i] = num;
        }
        return arr.size();
    }
};
