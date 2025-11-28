class Solution {
public:
    double average(vector<int>& salary) {
        int min = INT_MAX, max = INT_MIN;
        double sum = 0;
        for (int v : salary) {
            if (v < min) {
                min = v;
            }
            if (v > max) {
                max = v;
            }
            sum += v;
        }
        sum -= (min + max);
        return sum / (salary.size() - 2);
    }
};
