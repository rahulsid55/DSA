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
    vector<int> in;
    int i=0;
    void inorder(TreeNode *root){
        if(!root) return;
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
    void inorder2(TreeNode *root){
        if(!root) return;
        inorder2(root->left);
        root->val=in[i++];
        inorder2(root->right);
    }
    TreeNode* convertBST(TreeNode* root) {
        inorder(root);
        int n=in.size();
        for(int i=n-2;i>=0;i--){
            in[i]=in[i]+in[i+1];
        }

        inorder2(root);
        return root;
        
    
        
    }
};