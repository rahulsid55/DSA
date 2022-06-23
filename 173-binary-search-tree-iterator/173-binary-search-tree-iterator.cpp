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
class BSTIterator {
public:
     stack <TreeNode *> s;
    void pushALL(TreeNode *root){
        if(root){
            s.push(root);
            pushALL(root->left);
        }
    }
   
    BSTIterator(TreeNode* root) {
        pushALL(root);
        
    }
    int next() {
        TreeNode *temp=s.top();
        int x=temp->val;
        s.pop();
        if(temp->right){
            pushALL(temp->right);
        }
        return x;
    }
    
    bool hasNext() {
        return !s.empty();
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */