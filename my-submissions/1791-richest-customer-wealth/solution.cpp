class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int customers = accounts.size();
        int banks = accounts[0].size();
        int maxWealth = INT_MIN;
        for (int i = 0; i < customers; i++) {
            int sum = 0;
            for (int j = 0; j < banks; j++) {
                sum += accounts[i][j];
            }
            maxWealth = max(maxWealth, sum);
        }
        return maxWealth;
    }
};
