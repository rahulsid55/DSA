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
    queue <TreeNode *> q;
    bool found(TreeNode *root,TreeNode *par,int x){
        if(!root) return false;
        if(root->val==x){
            if(root->left){
                q.push(root->left);
            }
            if(root->right){
                q.push(root->right);
            }
            return true;
        }
        if(root->left and root->left->val==x){
            if(root->left->left){
                q.push(root->left->left);
            }
            if(root->left->right){
                q.push(root->left->right);
            }
            root->left=NULL;
            q.push(par);
            return true;
        }
        if(root->right and root->right->val==x){
            if(root->right->left){
                q.push(root->right->left);
            }
            if(root->right->right){
                q.push(root->right->right);
            }
            root->right=NULL;
            q.push(par);
            return true;
        }
        if(found(root->left,par,x) or found(root->right,par,x)) return true;
        return false;
            
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) { 
        vector<TreeNode *> ans;
        int n=to_delete.size();
        q.push(root);
        for(int i=0;i<n;i++){
            while(!q.empty()){
                TreeNode *x=q.front();
                q.pop();
                if(found(x,x,to_delete[i])){
                    break;    
                }
                q.push(x);
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
        
    }
};