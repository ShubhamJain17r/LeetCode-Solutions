class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XOR = 0;
        for (const int &val : nums)
            XOR ^= val;

        int bit = 1;
        while ((bit & XOR) == 0)
            bit <<= 1;
            
        int one = 0, two = 0;
        for (const int &val : nums) {
            if ((val & bit) == 0)
                one ^= val;
            else
                two ^= val;
        }
        return {one, two};
    }
};
