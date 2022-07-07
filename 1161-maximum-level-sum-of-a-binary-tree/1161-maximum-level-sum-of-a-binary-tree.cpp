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
    int maxLevelSum(TreeNode* root) {
        queue <TreeNode *> q;
        q.push(root);
        int x,maxi=INT_MIN,j=1;
        while(!q.empty()){
            int sum=0;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode *temp=q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            cout<<sum<<endl;
            if(sum>maxi){
                x=j;
                maxi=sum;
            }
            j++;
        }
        return x;
        
        
    }
};