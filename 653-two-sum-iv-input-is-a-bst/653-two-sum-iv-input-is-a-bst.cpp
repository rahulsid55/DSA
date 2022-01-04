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
   vector<int> nodes;
    void inorder(TreeNode *root){
        if(root){
            
            inorder(root->left);
            nodes.push_back(root->val);
            inorder(root->right);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int l=0,r=nodes.size()-1;
        
        cout<<r;
        while(l<r){
            int res=nodes[l]+nodes[r];
            
            if(res==k) return true;
            else if(res>k)
                r--;
            else
                l++;
        }
        return false;
    }
};