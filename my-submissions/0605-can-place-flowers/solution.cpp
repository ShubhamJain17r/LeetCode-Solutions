class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        if (n == 0) return true;
        if (flowerbed.size() < n) return false;

        if (flowerbed.size() == 1){
            if (flowerbed[0] == 1)
                return false;
            return true;
        }

        if (flowerbed[0] == 0 && flowerbed[1] == 0){
            n--;
            flowerbed[0] = 1;
        }

        for (int i = 1; i < (flowerbed.size() - 1) && n > 0; ++i){
            if (flowerbed[i] == 0 && flowerbed[i-1]==0 && flowerbed[i+1] == 0){
                flowerbed[i] = 1;
                n--;
            }
        }

        if (n>0 && flowerbed[flowerbed.size() - 1] == 0 && flowerbed[flowerbed.size() - 2] == 0){
            n--;
            flowerbed[flowerbed.size() - 1] = 1;
        }

        return n==0;
    }
};
