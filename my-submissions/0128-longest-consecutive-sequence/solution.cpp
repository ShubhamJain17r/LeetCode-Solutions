class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int val : s){
            if (s.count(val - 1)) continue;
            int curr = val;
            int streak = 1;
            while (s.count(curr + 1)){
                streak++;
                curr++;
            }
            longest = max(longest, streak);
        }
        return longest;
    }
};
