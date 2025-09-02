class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool negCount = true;
        for (int v : nums){
            if (v == 0) return 0;
            if (v < 0) negCount = !negCount;
        }
        if (negCount) return 1;
        return -1;
    }
};
