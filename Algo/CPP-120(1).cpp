// 120. Triangle
// Given a triangle array, return the minimum path sum from top to bottom.
// Time Limit Exceeded
class Solution {
public:
    int nextMin(vector<vector<int>>& triangle, int row, int col){
        if(row < triangle.size()){
            return min(nextMin(triangle,row+1,col),nextMin(triangle,row+1,col+1)) + triangle[row][col];
        }
        return 0;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        return nextMin(triangle,0,0);
    }
};