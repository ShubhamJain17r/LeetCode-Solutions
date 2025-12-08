class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int curr = 0, prev2 = 0, prev1 = cost[0];
        
        for (int i = 2; i <= n; ++i) {
            curr = cost[i - 1] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
};
