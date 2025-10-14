class Solution {
public:
    void combinationSumHelper(vector<int>& candidates, int target, vector<int>& subset, vector<vector<int>>& ans, int sum, int i){
        if (sum == target){
            ans.push_back(subset);
            return;
        }
        if (sum > target){
            return;
        }
        for (int j = i; j < candidates.size(); ++j){
            if (candidates[j] > target) return;
            subset.push_back(candidates[j]);
            sum += candidates[j];
            combinationSumHelper(candidates, target, subset, ans, sum, j);
            subset.pop_back();
            sum -= candidates[j];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (target == 1) return {};
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> subset;

        combinationSumHelper(candidates, target, subset, ans, 0, 0);

        return ans;
    }
};
