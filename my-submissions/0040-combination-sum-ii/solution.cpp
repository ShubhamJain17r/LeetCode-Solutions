class Solution {
public:
    void combinationSum2Helper(vector<int>& candidates, int target, vector<int>& subset, vector<vector<int>>& ans, int sum,int idx){
        if (sum == target){
            ans.push_back(subset);
            return;
        }
        for (int i = idx; i < candidates.size(); ++i){
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            subset.push_back(candidates[i]);
            if (sum + candidates[i] <= target)
                combinationSum2Helper(candidates, target, subset, ans, sum + candidates[i], i+1);
            subset.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> subset;

        combinationSum2Helper(candidates, target, subset, ans, 0, 0);

        return ans;

    }
};
