// 994. Rotting Oranges
// Using queue and fresh count
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int rotNum = 2;

        queue<pair<int,int>> rotten;
        int fresh_count = 0;

        pair<int,int> curr;
        
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == 1){
                    fresh_count++;
                }
                else if(grid[i][j] == 2){
                    rotten.push({i,j});
                }
            }
        }

        while(!rotten.empty() && fresh_count !=0){
            curr = rotten.front();
            rotten.pop();
            if(rotNum == grid[curr.first][curr.second])
            {
                rotNum++;
            }
            if(curr.first>0){
                if(grid[curr.first -1][curr.second] == 1){
                    grid[curr.first -1][curr.second] = rotNum;
                    rotten.push({curr.first -1,curr.second});
                    fresh_count--;
                }
            }
            if(curr.first<row-1){
                if(grid[curr.first +1][curr.second] == 1){
                    grid[curr.first +1][curr.second] = rotNum;
                    rotten.push({curr.first +1,curr.second});
                    fresh_count--;
                }
            }
            if(curr.second<col-1){
                if(grid[curr.first][curr.second+1] == 1){
                    grid[curr.first][curr.second+1] = rotNum;
                    rotten.push({curr.first,curr.second+1});
                    fresh_count--;
                }
            }
            if(curr.second>0){
                if(grid[curr.first][curr.second-1] == 1){
                    grid[curr.first][curr.second-1] = rotNum;
                    rotten.push({curr.first,curr.second-1});
                    fresh_count--;
                }
            }
        }

        if(fresh_count>0){
            return -1;
        }
        else{
            return rotNum-2;
        }
    }
};