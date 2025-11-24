class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxHeight = 0;
        int height = 0;
        for (int& val : gain) {
            val += height;
            maxHeight = max(maxHeight, val);
            height = val;
        }
        return maxHeight;
    }
};
