class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0, lMax = 0, rMax = 0;
        int s = 0, e = n - 1;

        while (s < e){
            if (height[e] < height[s]){
                if (height[e] < rMax)
                    total += rMax - height[e];
                else
                    rMax = height[e];
                e--;
            }
            else{
                if (height[s] < lMax)
                    total += lMax - height[s];
                else
                    lMax = height[s];
                s++;
            }
        }
        return total;
    }
};
