class Solution {
public:
int findMaximumXOR(vector<int>& nums) {
    int mask = 0, ans = 0;

    for (int bit = 31; bit >= 0; bit--) {
        mask |= (1 << bit);

        unordered_set<int> prefixes;
        for (int num : nums) {
            prefixes.insert(num & mask);
        }

        int candidate = ans | (1 << bit);

        for (int p : prefixes) {
            if (prefixes.count(p ^ candidate)) {
                ans = candidate;
                break;
            }
        }
    }
    return ans;
}
};
