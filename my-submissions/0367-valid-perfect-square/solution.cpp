class Solution {
public:
bool isPerfectSquare(int num) {
    if (num == 1)   return true;
    int l = 1, r = num / 2;
    while (l <= r) {
        int m = l + ((r - l) >> 2);
        // cout<<m<<endl;
        double target = num / (double)m;
        // cout<<target<<endl<<"---"<<endl;
        if (m == target)        return true;
        else if (m < target)    l = m + 1;
        else                    r = m - 1;
    }
    return false;
}
};
