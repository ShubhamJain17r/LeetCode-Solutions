class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int duplicate;
        vector<int> visited(n, false);
        for (int val : nums) {
            if (!visited[val-1])
                visited[val-1] = true;
            else
                duplicate = val;
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                return {duplicate, i+1};
        }
        return {-1,-1};
    }
};
