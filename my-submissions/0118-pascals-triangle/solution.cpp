class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for (int i = 1; i <= numRows; ++i){
            vector<int> row(i);
            row[0] = row[i-1] = 1;
            for (int j = 1; j < i - 1; ++j){
                row[j] = triangle[i - 2][j] + triangle[i - 2][j - 1]; 
            }
            triangle.push_back(row);
        }
        return triangle;
    }
};
