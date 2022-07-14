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
    int index=0;
    unordered_map<int,int> mp;
    TreeNode *solve(int i,int n,vector<int> preorder)
    {
        if(i>n)
            return NULL;
        int x=preorder[index++];
        TreeNode *root=new TreeNode(x);
        root->left=solve(i,mp[x]-1,preorder);
        root->right=solve(mp[x]+1,n,preorder);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        
        return solve(0,preorder.size()-1,preorder);
        
    }
};