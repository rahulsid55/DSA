/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    void solve(Node *root)
    {
        if(!root) return;
        if(!root->left and !root->right) return;
        root->left->next=root->right;
        solve(root->left);
            if(root->next)
            {
                root->right->next=root->next->left;
            }
            else
            {
                root->next=NULL;
            }
        solve(root->right);
        return;
    }
public:
    Node* connect(Node* root) {
        solve(root);
        return root;
        
        
        
    }
};