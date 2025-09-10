class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& curr, int start){
        if (target == 0){
            ans.push_back(curr);
            return;
        }
        if (target < 0) return;

        for (int i = start; i < candidates.size(); ++i){
            curr.push_back(candidates[i]);
            helper(candidates, target - candidates[i], ans, curr, i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        helper(candidates, target, ans, curr, 0);

        return ans;
    }
};
