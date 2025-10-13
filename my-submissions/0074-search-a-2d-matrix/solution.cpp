class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int s = 0, e = rows - 1;
        while (s <= e){
            int m = s + (e - s) / 2;
            if (matrix[m][0] <= target && matrix[m][cols - 1] >= target){
                int s_ = 0, e_ = cols - 1;
                while (s_ <= e_){
                    int m_ = s_ + (e_ - s_)/2;
                    if (matrix[m][m_] == target) return true;
                    else if (matrix[m][m_] < target) s_ = m_ + 1;
                    else e_ = m_ - 1;
                }
                return false;
            }
            else if (matrix[m][0] > target) e = m - 1;
            else s = m + 1;
        }
        return false;
    }
};
