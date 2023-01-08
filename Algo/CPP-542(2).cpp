// 542. 01 Matrix
// Dynamic programming(puff and trim)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> result(row, vector<int> (col, row + col));
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(mat[i][j] == 0){
                    result[i][j] = 0;
                }
                else{
                    if(i>0) {
                        result[i][j] = min(result[i][j],result[i-1][j]+1);
                    }
                    if(j > 0) {
                        result[i][j] = min(result[i][j],result[i][j-1]+1);
                    }
                }
            }
        }

        for(int i = row-1; i>-1; i--){
            for(int j = col-1; j>-1; j--){
                if(result[i][j] != 0){
                    if(i+1 < row) {
                        result[i][j] = min(result[i][j],result[i+1][j]+1);
                    }
                    if(j+1 < col) {
                        result[i][j] = min(result[i][j],result[i][j+1]+1);
                    }
                }
            }
        }
        return result;
    }
};