// 733. Flood Fill
class Solution {
public:
    void fillColor(vector<vector<int>>& image, int sr, int sc, int color, int old) {        
        if(image[sr][sc] != color && image[sr][sc] == old) {            
            image[sr][sc] = color;

            int row = image.size()-1;
            int col = image[0].size()-1;

            if(sr>0) fillColor(image,sr-1,sc,color,old);
            if(sr<row) fillColor(image,sr+1,sc,color,old);
            if(sc>0) fillColor(image,sr,sc-1,color,old);
            if(sc<col) fillColor(image,sr,sc+1,color,old);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        fillColor(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};