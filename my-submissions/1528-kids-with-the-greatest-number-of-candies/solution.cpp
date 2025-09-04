class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = 0;
        for (int val : candies){
            if (val > max) max = val; 
        }

        int n = candies.size();
        vector<bool> ans(n, false);

        for (int i = 0; i<n; ++i){
            if (candies[i] + extraCandies >= max){
                ans[i] = true;
            }
        }
        return ans;
    }
};
