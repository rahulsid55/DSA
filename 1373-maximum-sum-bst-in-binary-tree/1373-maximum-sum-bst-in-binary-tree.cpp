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
class Pair{
    public:
    bool isBst;
    int mini;
    int maxi;
    int sum;
};
class Solution {
public:
    Pair help(TreeNode* root,int &ans){
        if(!root){
            Pair bp;
            bp.sum=0;
            bp.mini=INT_MAX;
            bp.maxi=INT_MIN;
            bp.isBst=true;
            return bp;
        }
        Pair a,b;
        a=help(root->left,ans);
        b=help(root->right,ans);
        Pair res;
        res.mini=min({root->val,a.mini,b.mini});
        res.maxi=max({root->val,a.maxi,b.maxi});
        bool flag=false;
        if(a.isBst and b.isBst and root->val>a.maxi and root->val<b.mini){
            flag=true;
        }
            res.isBst=flag;
        if(flag){
            res.sum=root->val+a.sum+b.sum;
            ans=max(ans,res.sum);
        }
        else{
            res.sum=INT_MIN;
        }
        return res;
        }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        help(root,ans);
        return ans;
    }
};