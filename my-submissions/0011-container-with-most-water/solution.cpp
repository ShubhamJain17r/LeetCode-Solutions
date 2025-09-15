class Solution {
public:
    int maxArea(vector<int>& height) {
        int mostWater = 0;
        int l = 0, r = height.size() - 1;

        while (l < r){
            int curr = (r - l) * min(height[l], height[r]);
            mostWater = max(mostWater, curr);

            if (height[l] < height[r])l++;
            else r--;
        }
        return mostWater;
    }
};
