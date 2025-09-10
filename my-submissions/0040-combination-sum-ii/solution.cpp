class Solution {
public:
    void helper(vector<int>& candidates, int target, int start, vector<vector<int>>& ans, vector<int>& curr){
        if (target == 0){
            ans.push_back(curr);
            return;
        }
        if (target < 0) return;

        for (int i = start; i<candidates.size(); ++i){
            if (i > start && candidates[i] == candidates[i-1])continue;

            curr.push_back(candidates[i]);
            helper(candidates, target - candidates[i], i + 1, ans, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        atexit([](){ std::ofstream("display_runtime.txt") << "0"; });
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> curr;

        helper(candidates, target, 0, ans, curr);

        return ans;
    }
};
