class Solution {
public:
    void combinationSum3Helper(int k, int n, int idx, vector<int> &temp, vector<vector<int>> &ans) {
        if (k == 0) {
            if (n == 0)
                ans.push_back(temp);                
            return;
        }
        for (int i = idx; i <= 9; i++) {
            if (i > n) return;
            temp.push_back(i);
            combinationSum3Helper(k - 1, n - i, i + 1, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> ans;
        combinationSum3Helper(k, n, 1, temp, ans);
        return ans;
    }
};
