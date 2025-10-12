class Solution {
public:
    int mySqrt(int x) {
        int s = 1, e = x, ans = 0;
        while (s <= e){
            int m = s + (e - s) / 2;
            if (m == x/m) return m;
            else if (m < x/m) {
                ans = m;
                s = m + 1;
            }
            else e = m - 1;
        }
        return ans;
    }
};
