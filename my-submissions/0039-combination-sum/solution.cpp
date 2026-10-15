class Solution {
public:
    void f(vector<int>& candidates, int target, vector<int>& vec, vector<vector<int>>& ans, int idx) {
        if (target == 0) {
            ans.push_back(vec);

            return;
        }
        if (idx == candidates.size()) return;

        if (candidates[idx] <= target)
        {
            vec.push_back(candidates[idx]);
            f(candidates, target - candidates[idx], vec, ans, idx);
            vec.pop_back();

            f(candidates, target, vec, ans, idx + 1);   
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> vec;

        sort(candidates.begin(), candidates.end());

        f(candidates, target, vec, ans, 0);

        return ans;
    }
};
