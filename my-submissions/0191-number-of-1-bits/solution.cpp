
class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        string s;
        while(n){
          if(n & 1){
            cnt++;
          }

          n = n >> 1;
        }
       return cnt;
    }
};
