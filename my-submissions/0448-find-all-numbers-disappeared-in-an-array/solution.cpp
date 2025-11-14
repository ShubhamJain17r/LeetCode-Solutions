class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n =  nums.size();
        vector<bool> visited(n, false);
        for (int val : nums) 
            visited[val-1] = true;
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (!visited[i])
                res.push_back(i+1);
        }
        return res;
    }
};
