/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* binarytree(vector<int>& preorder, vector<int>& inorder,int start,int right,int& first){
    if (start > right || first >= preorder.size()) {
    return NULL;
}
    TreeNode* root = new TreeNode(preorder[first]);
    first++;

    int i = start;
    for (i = start; i <= right; i++) {
    if (inorder[i] == root->val) {
        break;
    }
}


   root->left = binarytree(preorder, inorder, start, i - 1, first);
root->right = binarytree(preorder, inorder, i + 1, right, first);

    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int first = 0;
       int start = 0;
       return binarytree(preorder,inorder,start,inorder.size()-1,first); 
    }
};