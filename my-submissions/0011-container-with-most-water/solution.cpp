class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0, currArea = 0;
        int s = 0, e = height.size() - 1;
        while (s < e){
            currArea = (e - s) * min(height[s], height[e]);
            maxArea = max(maxArea, currArea);
            if (height[s] < height[e])
                s++;
            else
                e--;
        }
        return maxArea;
    }
};
