class Solution {
private:
    static bool comp(vector<int>& p1, vector<int>& p2) {
        return p1[1] < p2[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);

        int arrows = 1;
        int endTime = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > endTime) {
                arrows++;
                endTime = points[i][1];
            }
        }
        return arrows;
    }
};
