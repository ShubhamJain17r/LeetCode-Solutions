class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiralMatrix;
        int rows = matrix.size();
        int cols = matrix[0].size();

        int sRow = 0, eRow = rows-1, sCol = 0, eCol = cols-1;

        while (sCol <= eCol && sRow <= eRow){
            if (sCol <= eCol){
                for (int j = sCol; j <= eCol; ++j)
                    spiralMatrix.push_back(matrix[sRow][j]);
                sRow++;
            }else break;
            if (sRow <= eRow){
                for (int i = sRow; i <= eRow; ++i)
                    spiralMatrix.push_back(matrix[i][eCol]);
                eCol--;
            }else break;
            if (sCol <= eCol){
                for (int j = eCol; j >= sCol; --j)
                    spiralMatrix.push_back(matrix[eRow][j]);
                eRow--;
            }else break;
            if (sRow <= eRow){
                for (int i = eRow; i >= sRow; --i)
                    spiralMatrix.push_back(matrix[i][sCol]);
                sCol++;
            }else break;
        }
        return spiralMatrix;
    }
};
