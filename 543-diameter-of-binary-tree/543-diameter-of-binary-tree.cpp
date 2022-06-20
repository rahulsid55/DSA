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
    int height(TreeNode *root){
        if(root){
            return 1+max(height(root->left),height(root->right));
        }
        return -1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root){
            return max({2+height(root->right)+height(root->left),diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)});
        }
        return 0;
    }
};