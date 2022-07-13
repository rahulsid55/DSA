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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue <TreeNode *> q;
        q.push(root);
        TreeNode *temp =new TreeNode(99999);
        
        vector<vector<int>> v;
       if(root==NULL)
           return v;
        while(!q.empty())
        {
          int x=q.size();
            vector<int> ds;
            while(x--)
            {
                TreeNode *t=q.front();
                ds.emplace_back(q.front()->val);
                q.pop();
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
             v.push_back(ds);
        }
       
        return v;
        
    }
};