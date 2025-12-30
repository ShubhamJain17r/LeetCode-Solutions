class Solution {
public:
    void combinationSumHelper(vector<int> &candidates, int target, int idx, vector<int> &temp, vector<vector<int>> &ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (idx == candidates.size()) return;

        for (int i = idx; i < candidates.size(); i++) {
            int val = candidates[i];
            if (val > target) return;
            temp.push_back(val);
            combinationSumHelper(candidates, target - val, i, temp, ans);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        combinationSumHelper(candidates, target, 0, temp, ans);
        return ans;
    }
};
