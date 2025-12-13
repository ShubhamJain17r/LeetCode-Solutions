class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int &v : nums) {
            ones = (v ^ ones) & ~twos;
            twos = (v ^ twos) & ~ones;
        }
        return ones;
    }
};
