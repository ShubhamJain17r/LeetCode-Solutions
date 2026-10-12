class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;

        // while (x || y) {
        //     cnt += ((x & 1) ^ (y & 1));

        //     x >>= 1;
        //     y >>= 1;
        // }

        int XOR = x ^ y;

        while (XOR) {
            cnt += (XOR & 1);

            XOR >>= 1;
        }

        return cnt;
    }
};
