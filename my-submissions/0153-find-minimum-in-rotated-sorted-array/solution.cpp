class Solution {
public:
    int findMin(vector<int>& arr) {
        int l = 0, h = arr.size() - 1;

        while (l < h) {
            int m = l + ((h - l) >> 1);

            if (arr[m] >= arr[l]) {      // left side sorted
                if (arr[l] <= arr[h]) {  // min present in left side
                    return arr[l];
                }
                else {                  // min present in right side
                    l = m + 1;
                }
            }
            else {                      // right side sorted
                if (arr[h] >= arr[l]) {  // min present in right side
                    return arr[m];
                }
                else {
                    h = m;
                }
            }
        }

        return arr[h];
    }
};
