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
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        function<Node*(int, int, int)> build = [&](int x, int y, int len) -> Node* {
            bool same = true;
            int val = grid[x][y];
            for(int i=x; i<x+len; ++i)
            for(int j =y; j<y+len; ++j)
            if(grid[i][j] != val) same =false;
            if(same) return new Node(val, true);
            int mid = len/2;
            return new Node{
                true, false,
                build(x,y,mid),
                build(x,y+mid,mid),
                build(x+mid,y,mid),
                build(x+mid,y+mid,mid),
            };
        };
        return build(0,0,n);
    }
};