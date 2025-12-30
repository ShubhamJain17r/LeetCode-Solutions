class Solution {
public:
    void combinationSum2Helper(vector<int>& candidates, int target, int idx, vector<int> &temp, vector<vector<int>> &ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (idx == candidates.size()) return;
        for (int i = idx; i < candidates.size(); ++i) {
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            int val = candidates[i];
            if (val > target) return;

            temp.push_back(val);
            combinationSum2Helper(candidates, target - val, i + 1, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        combinationSum2Helper(candidates, target, 0, temp, ans);
        return ans;
    }
};
