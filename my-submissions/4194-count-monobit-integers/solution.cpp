class Solution {
public:
    int countMonobit(int n) {
        if (n <= 1) return n + 1;
        int cnt = 0;
        int x = n;
        while (x) {
            cnt++;
            x = (x >> 1);
        }
        return (((n + 1) & (n)) == 0) ? cnt + 1 : cnt;
    }
};
