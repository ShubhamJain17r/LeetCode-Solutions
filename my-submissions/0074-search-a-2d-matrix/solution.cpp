class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int i = 0, j = rows-1;
        while (i <= j){
            int m = i + (j - i)/2;
            if (matrix[m][0] <= target && matrix[m][cols-1]>=target) {
                int s = 0, e = cols-1;
                while (s <= e){
                    int mid = s + (e - s)/2;
                    if (matrix[m][mid] == target) return true;
                    else if (matrix[m][mid] < target) s = mid+1;
                    else e = mid-1; 
                }
                return false;
            }
            else if (matrix[m][0] < target) i = m+1;
            else j = m-1;
        }
        return false;
    }
};
