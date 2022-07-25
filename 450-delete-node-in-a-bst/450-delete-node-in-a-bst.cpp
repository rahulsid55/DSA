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
    TreeNode *solve(TreeNode *x){
        if(!x->left) return x->right;
        if(!x->right) return x->left;
        TreeNode *tempr=x->right;
        TreeNode *templ=x->left;
        while(templ->right){
            templ=templ->right;
        }
        templ->right=tempr;
        return x->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        TreeNode *ans=root;
        if(root->val==key){
            return solve(root);
        }
        
        while(root){
            if(root->val>key){
                if(root->left  and root->left->val==key){
                    root->left=solve(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
           else if(root->val<key){
                if(root->right  and root->right->val==key){
                    root->right=solve(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
        return ans;
        
    }
};