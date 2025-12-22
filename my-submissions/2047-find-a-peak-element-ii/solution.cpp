class Solution {
public:
    int findMaxCol(vector<vector<int>>& mat, int col) {
        int maxi = 0;
        int idx = -1;
        int n = mat.size();
        for (int i = 0; i < n; ++i) {
            if (mat[i][col] > maxi) {
                maxi = mat[i][col];
                idx = i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int l = 0, r = m - 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            int maxIdx = findMaxCol(mat, mid);

            int midEl = mat[maxIdx][mid];

            int left = (mid - 1 >= 0) ? mat[maxIdx][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[maxIdx][mid + 1] : -1;

            if (midEl > left && midEl > right) return {maxIdx, mid};
            if (midEl < left)                  r = mid - 1;
            else                               l = mid + 1;
        }
        return {-1, -1};
    }
};
