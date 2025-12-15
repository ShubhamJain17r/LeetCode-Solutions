class Solution {
public:
    static bool comp(vector<int>& i1, vector<int>& i2) {
        return i1[1] < i2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int ans = 0;
        int endTime = INT_MIN;
        for (vector<int> &I : intervals) {
            if (I[0] < endTime) ans++;
            else {
                endTime = I[1];
            }
        }
        return ans;
    }
};
