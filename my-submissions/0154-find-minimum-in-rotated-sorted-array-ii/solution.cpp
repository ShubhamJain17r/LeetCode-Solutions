class Solution {
public:
    int findMin(vector<int>& arr) {
        int l = 0, h = arr.size() - 1;

        while (l < h) {
            int m = l + ((h - l) >> 1);

            if (arr[m] > arr[l]) {
                if (arr[l] < arr[h]) {
                    return arr[l];
                }
                else {
                    l = m + 1;
                }
            }
            else if (arr[m] < arr[h]){
                if (arr[h] > arr[l]) {
                    return arr[m];
                }
                else {
                    h = m;
                }
            }
            else {
                l++;
            }
        }

        return arr[h];
    }
};
