class Solution {
private:
    static bool comp(vector<int>& i1, vector<int>& i2) {
        return i1[1] < i2[1];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        
        int cnt = 0;
        int endTime = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < endTime) {
                cnt++;
            }
            else {
                endTime = intervals[i][1];
            }
        }
        return cnt;
    }
};
