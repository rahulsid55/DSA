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
    int heightR(TreeNode *root){
        int ct=0;
        while(root){
            ct++;
            root=root->right;
        }
        return ct;
    }
    int heightL(TreeNode *root){
        int ct=0;
        while(root){
            ct++;
            root=root->left;
        }
        return ct;
    }
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int lh=heightL(root);
        int rh=heightR(root);
        if(lh==rh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};