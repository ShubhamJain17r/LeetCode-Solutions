class Solution {
public:
    void swap(int&a, int& b) {
        a^=b;
        b^=a;
        a^=b;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int m = INT_MIN, sm = INT_MIN;
        int maxIdx = -1, smaxIdx = -1;

        m = nums[1], maxIdx = 1;
        sm = nums[0], smaxIdx = 0;

        if (sm > m) {
            swap(sm,m);
            swap(maxIdx, smaxIdx);
        }
        for (int i = 2; i < n; ++i) {
            if (maxIdx != i - 1) {
                sm = m;
                smaxIdx = maxIdx;
                m += nums[i];
                maxIdx = i;
            }
            else {
                sm += nums[i];
                smaxIdx = i;
            }
            if (sm > m) {
                swap(sm,m);
                swap(maxIdx, smaxIdx);
            }
        }
        return m;
    }
};
