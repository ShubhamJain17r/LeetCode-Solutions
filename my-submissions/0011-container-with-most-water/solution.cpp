class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxWater = 0;
        int st = 0, ed = n - 1;
        while (st < ed) {
            int curr = (ed - st) * min(height[st], height[ed]);
            if (height[st] < height[ed])
                st++;
            else
                ed--;
            maxWater = max(curr, maxWater);
        }
        return maxWater;
    }
};
