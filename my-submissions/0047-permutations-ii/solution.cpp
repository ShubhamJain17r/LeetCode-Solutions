class Solution {
public:
void permuteUniqueHelper(vector<int> nums, int start, vector<vector<int>>& ans){
    if (start == nums.size()){
        ans.push_back(nums);
        return;
    }

    for (int i = start; i<nums.size(); ++i){
        if (i > start && nums[i] == nums[start])continue;

        swap(nums[i], nums[start]);
        permuteUniqueHelper(nums, start + 1, ans);
        // swap(nums[i], nums[start]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    permuteUniqueHelper(nums, 0, ans);
    return ans;
}
};

// class Solution {
// public:
//     void helper(vector<int> nums, int start, vector<vector<int>>& ans){
//         if (start == nums.size()){
//             ans.push_back(nums);
//             return;
//         }

//         for (int i = start; i<nums.size(); ++i){
//             if (i > start && nums[i] == nums[start])continue;

//             swap(nums[i], nums[start]);
//             helper(nums, start + 1, ans);
//             // swap(nums[i], nums[start]);
//         }
//     }
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         vector<vector<int>> ans;

//         helper(nums, 0, ans);

//         return ans;
//     }
// };
