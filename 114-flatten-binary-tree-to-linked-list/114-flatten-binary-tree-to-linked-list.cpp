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
    void flatten(TreeNode* root) {
        if(!root) return;
        if(!root->left and !root->right) return;
        TreeNode *temp=root->right;
        TreeNode *temp1=root->left;
        flatten(root->left);
        flatten(temp);
        root->right=temp1;
        root->left=NULL;
        while(root->right!=NULL){
            root=root->right;
            
        }
        
        root->right=temp;
        
        
    }
};