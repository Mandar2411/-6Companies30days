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
    Node* construct(vector<vector<int>>& grid, int x, int y, int size) {
        if(size == 1) 
            return new Node(grid[x][y], true);
        
        int val = grid[x][y];
        bool allSame = true;
        
        for(int i=0; i<size && allSame; i++) {
            for(int j=0; j<size; j++) {
                if(grid[x+i][y+j] != val) {
                    allSame = false;
                    break;
                }
            }
        }

        if(allSame) 
            return new Node(grid[x][y], true);
        
        Node* root = new Node(grid[x][y], false);
        root->topLeft = construct(grid, x, y, size/2);
        root->topRight = construct(grid, x, y+size/2, size/2);
        root->bottomLeft = construct(grid, x+size/2, y, size/2);
        root->bottomRight = construct(grid, x+size/2, y+size/2, size/2);    
        
        return root;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return construct(grid, 0, 0, grid.size());
    }
};