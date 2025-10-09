class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        int count = 0;
        int sum = 0;

        for (int val : nums){
            sum += val;

            if (prefixCount.find(sum - k) != prefixCount.end())
                count += prefixCount[sum - k];
            prefixCount[sum]++;
        }
        return count;
    }
};
