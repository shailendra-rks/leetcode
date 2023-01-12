// 120. Triangle
// Given a triangle array, return the minimum path sum from top to bottom.(DP,DFS)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<int> low(row, 0);

        for(int i = 0; i< row; i++){
            low[i] = triangle[row-1][i];
        }

        for(int i = row-2; i>=0; i--){
            vector<int> hi(row, 0);
            for(int j = i; j>=0; j--){
                hi[j] = min(low[j],low[j+1]) + triangle[i][j];
            }
            low = hi;
        }
        return low[0];
    }
};