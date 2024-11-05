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
Node* constructT(std::vector<std::vector<int>>& grid, int rowStart, int rowEnd, int colStart, int colEnd) {
     if (rowStart > rowEnd || colStart > colEnd) return nullptr;

        bool isUniform = true;
        int firstValue = grid[rowStart][colStart];

        for (int i = rowStart; i <= rowEnd; ++i) {
            for (int j = colStart; j <= colEnd; ++j) {
                if (grid[i][j] != firstValue) {
                    isUniform = false;
                    break;
                }
            }
            if (!isUniform) break;
        }

        if (isUniform) {
            return new Node(firstValue, true);
        }

        int midRow = (rowStart + rowEnd) / 2;
        int midCol = (colStart + colEnd) / 2;

        return new Node(
            true, // Placeholder value for non-leaf nodes
            false,
            constructT(grid, rowStart, midRow, colStart, midCol),
            constructT(grid, rowStart, midRow, midCol + 1, colEnd),
            constructT(grid, midRow + 1, rowEnd, colStart, midCol),
            constructT(grid, midRow + 1, rowEnd, midCol + 1, colEnd)
        );
    }

    Node* construct(vector<vector<int>>& grid) {
         return constructT(grid, 0, grid.size() - 1, 0, grid[0].size() - 1); 
    }
};