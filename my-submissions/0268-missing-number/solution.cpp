class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int XOR = 0;
        for (const int &val : nums)
            XOR ^= val;
        int n = nums.size();
        if (n % 4 == 0) return n ^ XOR;
        if (n % 4 == 1) return 1 ^ XOR;
        if (n % 4 == 2) return (n + 1) ^ XOR;
        return XOR;
    }
};
