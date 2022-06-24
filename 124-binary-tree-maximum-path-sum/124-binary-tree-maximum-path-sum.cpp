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
    int solve(TreeNode *root,int &result)
    {
        if(!root)
        {
            return 0;
        }
        int lefti=solve(root->left,result);
        int righti=solve(root->right,result);
        int ms1=max(max(lefti,righti)+root->val,root->val);
        int ms2=max(root->val+lefti+righti,ms1);
        result=max(result,ms2);
        return ms1;
    }

public:
    int maxPathSum(TreeNode* root) {
        int result=INT_MIN;
         solve(root,result);
        return result;
            
        
    }
};