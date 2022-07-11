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
    void right(TreeNode *root,map<int,int> &mp,int i)
    {
        if(root==NULL) return;
        mp[i]=root->val;
        right(root->left,mp,i+1);
        right(root->right,mp,i+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        map<int,int> mp;
        right(root,mp,0);
        vector<int> ans;
        for(auto [a,b] : mp)
        {
            ans.push_back(b);
        }
        return ans;
        
    }
};