class Solution {
public:
void subsetsWithDupHelper(vector<int>& nums, int idx, vector<vector<int>> &subsets, vector<int> &temp) {
    subsets.push_back(temp);
    for (int i = idx; i < nums.size(); ++i) {
        if (i > idx && nums[i] == nums[i - 1]) continue;
        temp.push_back(nums[i]);
        subsetsWithDupHelper(nums, i + 1, subsets, temp);
        temp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> subsets;
    vector<int> temp;
    subsetsWithDupHelper(nums, 0, subsets, temp);
    return subsets;
}
};
