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
    Node* traverse(vector<vector<int>>& grid, int t, int b, int l, int r) {
        int len = r - l + 1, sum = 0;
        for(int i = t; i <= b; i++) {
            for(int j = l; j <= r; j++) sum += grid[i][j];
        }
        if((sum == 0) || (sum == len * len)) return new Node(sum > 0, true);
        int lmid = l + len / 2, tmid = t + len / 2;
        return new Node(
            false,
            false,
            traverse(grid, t, tmid - 1, l, lmid - 1),
            traverse(grid, t, tmid - 1, lmid, r),
            traverse(grid, tmid, b, l, lmid - 1),
            traverse(grid, tmid, b, lmid, r)
        );
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return traverse(grid, 0, n - 1, 0, n - 1);
    }
};
