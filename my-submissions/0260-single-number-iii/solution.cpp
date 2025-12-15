class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long XOR = 0;
        for (int &x : nums) XOR ^= x;
        long fcb = XOR ^ (XOR & (XOR - 1));
        int b1 = 0, b2 = 0;
        for (int &x : nums) {
            if (x & fcb) b1 ^= x;
            else         b2 ^= x;
        }
        return {b1, b2};
    }
};
