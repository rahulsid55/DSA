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
    map<string,int> mp;
    vector<TreeNode *> ans;
    string solve(TreeNode *root){
        if(!root) return "";
        string temp=to_string(root->val)+"$"+solve(root->left)+"$"+solve(root->right);
        cout<<temp<<" ";
        if(mp[temp]==1){
            //cout<<root->val<<endl;
            ans.push_back(root);
            cout<<ans.size()<<" ";
        }
        mp[temp]++;
        return temp;
        
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        return ans;
        
    }
};