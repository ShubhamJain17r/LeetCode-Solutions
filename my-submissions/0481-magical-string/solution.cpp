class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;  // magical string begins with "122"

        vector<int> s(n + 1);
        s[0] = 1; 
        s[1] = 2;
        s[2] = 2;

        int head = 2;      // reading pointer
        int tail = 3;      // writing pointer
        int num = 1;       // next number to write
        int countOnes = 1; // count of 1s in the first n chars

        while (tail < n) {
            int freq = s[head]; // how many times to write 'num'

            while (freq-- && tail < n) {
                s[tail] = num;
                if (num == 1) countOnes++;
                tail++;
            }

            num ^= 3; // toggle 1 ↔ 2 using XOR trick
            head++;
        }

        return countOnes;
    }
};

