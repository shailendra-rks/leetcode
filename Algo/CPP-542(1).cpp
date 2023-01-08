// 542. 01 Matrix
// Time Limit Exceeded(DFSx(m+n))
class Solution {
public:
    int getDistance(vector<vector<int>>& mat, int sr, int sc, int step){
        bool zero_found = false;
        for(int i = 0; i <= step; i++){
            int j = step - i;
            if(sr+i<mat.size()){
                if(sc+j<mat[0].size()){
                    if(mat[sr+i][sc+j] == 0){
                        zero_found = true;
                        break;
                    }
                }
                if(sc-j >-1){
                    if(mat[sr+i][sc-j] == 0){
                        zero_found = true;
                        break;
                    }
                }
            }
            if(sr-i>-1){
                if(sc+j<mat[0].size()){
                    if(mat[sr-i][sc+j] == 0){
                        zero_found = true;
                        break;
                    }
                }
                if(sc-j >-1){
                    if(mat[sr-i][sc-j] == 0){
                        zero_found = true;
                        break;
                    }
                }
            }
        }
        
        if(zero_found){
            return step;
        }
        else{
            return getDistance(mat,sr,sc,step+1);
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        for(int i = 0; i<mat.size(); i++){
            for(int j = 0; j<mat[0].size(); j++){
                if(mat[i][j] != 0){
                    mat[i][j] = getDistance(mat,i,j,1);
                }
            }
        }
        return mat;
    }
};