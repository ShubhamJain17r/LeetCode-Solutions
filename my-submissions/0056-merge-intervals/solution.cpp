
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            }
        );

        vector<vector<int>> output;

        output.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {

            const vector<int>& interval = intervals[i];

            if (interval[0] <= output.back()[1]) {
                output.back()[1] = max(interval[1], output.back()[1]);
            }
            else {
                output.push_back(interval);
            }
        }

        return output;
    }
};

