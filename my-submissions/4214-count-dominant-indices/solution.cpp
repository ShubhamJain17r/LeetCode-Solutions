class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int sum = 0;

        for (int i = n - 1; i >= 0; --i) {
            sum += nums[i];
            double avg = static_cast<double>(sum) / (n - i);

            if (nums[i] > avg) 
                cnt++;
        }

        return cnt;
    }
};
