class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long sum = n * (n + 1) / 2;

        for (int val : nums)
            sum -= val;
        return sum;
    }
};
