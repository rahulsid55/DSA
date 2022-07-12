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
    int maxi=0;
    pair<int,int> solve(TreeNode *root){
        if(!root) return {-1,INT_MAX};
         pair<int,int> l,r;
        l=solve(root->left);
        r=solve(root->right);
        pair<int,int> res;
        res.first=1;
        maxi=max(maxi,max(l.first,r.first));
        int x=l.second,y=r.second,z=root->val;
        if(x==z and y==z){
            maxi=max(maxi,2+l.first+r.first);
            return {1+max(l.first,r.first),root->val};
        }
        if(x==z and y!=z){
            maxi=max(maxi,1+l.first);
            return {1+l.first,root->val};
        }
        if(x!=z and y==z){
            maxi=max(maxi,1+r.first);
            return {1+r.first,root->val};
        }
        return {0,root->val};
        
        
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        pair<int,int> ans=solve(root);
        maxi=max(maxi,ans.first);
        return maxi;
        
    }
};