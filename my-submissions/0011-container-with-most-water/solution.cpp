class Solution {
public:
int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int maxA = INT_MIN;
    while (l < r) {
        int water = (r - l) * min(height[l], height[r]);
        maxA = max(maxA, water);
        if (height[l] < height[r])
            l++;
        else 
            r--;
    }
    return maxA;
}
};
