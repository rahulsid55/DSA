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
    int cost=0;
    pair<int,int> solve(TreeNode* root){
        if(!root) return {0,0};
        pair<int,int> l,r;
        l=solve(root->left);
        r=solve(root->right);
        cout<<l.first<<" "<<l.second<<" ";
        cout<<root->val<<" ";
        cout<<r.first<<" "<<r.second<<" ";
        cout<<endl;
        cost+=(l.first+l.second+r.first+r.second);
        if(root->val==0){
            int excess=l.first+r.first;
            int req=l.second+r.second+1;
            if(excess>=req) return {excess-req,0};
            else return {0,req-excess};
        }
        else{
            int excess=l.first+r.first+(root->val-1);
            int req=l.second+r.second;
            if(excess>=req) return {excess-req,0};
            else return {0,req-excess};
        }
        
    }
    int distributeCoins(TreeNode* root) {
        solve(root);
        return cost;
    }
};