class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; ++i){
            for (int j = i; j < n; ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int row = 0; row < n; ++row){
            int s = 0, e = n - 1;
            while (s < e){
                swap(matrix[row][s++], matrix[row][e--]);
            }
        }
    }
};
