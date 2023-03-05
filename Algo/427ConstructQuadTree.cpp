/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* createQuadTree(vector<vector<int>>& grid,int size,int x, int y){
        if(size == 1){
            return new Node(grid[x][y],true);
        }

        Node* topLeft = createQuadTree(grid, size/2, x, y);
        Node* topRight = createQuadTree(grid, size/2, x, y+size/2);
        Node* bottomLeft = createQuadTree(grid, size/2, x+size/2, y);
        Node* bottomRight = createQuadTree(grid, size/2, x+size/2, y+size/2);

        if(topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && 
            topLeft->val==topRight->val && topRight->val==bottomLeft->val && bottomLeft->val==bottomRight->val){
                return new Node(grid[x][y],true);
        }

        return new Node(true,false,topLeft,topRight,bottomLeft,bottomRight);
    }
    Node* construct(vector<vector<int>>& grid) {
        return createQuadTree(grid,grid.size(),0,0);
    }
};