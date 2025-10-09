class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];  // Sort by first element
        });

        vector<vector<int>> ans;
        int startI = intervals[0][0], endI = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i){
            if (intervals[i][0] <= endI)
               endI = max(endI, intervals[i][1]);
            else {
                ans.push_back({startI, endI});
                startI = intervals[i][0];
                endI = intervals[i][1];
            }
        }
        ans.push_back({startI, endI});
        return ans;
    }
};
