class Solution {
public:
    inline int ceil(int a, int b) {
        if (a % b == 0) {
            return a / b;
        }
        return (a / b) + 1;
    }
    int func(vector<int>& piles, int k) {
        int time = 0;
        for (int pile : piles) {
            int t = ceil(pile, k);
            time += t;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int start = 0, end = 0, ans;
        long long sum = 0;
        for (int pile : piles) {
            sum += pile;
            end = max(end, pile);
        }
        start = sum / h;
        start = max(start, 1);

        while (start <= end) {
            int m = start + ((end - start) >> 1);
            int time = func(piles, m) ;
            if (time <= h) {
                end = m - 1;
                ans = m;
            }
            else {
                start = m + 1;
            }
        }
        return ans;
    }
};
