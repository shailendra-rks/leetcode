// 695. Max Area of Island
class Solution {
public:
    int recursiveCount(vector<vector<int>>& grid,int sr,int sc) {
        if(grid[sr][sc] == 1){
            int count = 1;
            grid[sr][sc] = 2;

            if(sr>0){
                count = count + recursiveCount(grid,sr-1,sc);
            }
            if(sr<grid.size()-1){
                count = count + recursiveCount(grid,sr+1,sc);
            }
            if(sc>0){
                count = count + recursiveCount(grid,sr,sc-1);
            }
            if(sc<grid[0].size()-1){
                count = count + recursiveCount(grid,sr,sc+1);
            }
            return count;
        }
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        int curr;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    curr = recursiveCount(grid,i,j);
                    max = (max > curr) ? max : curr;
                }
                // else if(grid[i][j] == 2){
                //     grid[i][j] = 1;
                // }
            }
        }
        return max;
    }
};