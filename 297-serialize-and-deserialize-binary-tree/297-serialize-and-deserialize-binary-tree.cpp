/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode *> q;
        string str="";
        q.push(root);
        while(!q.empty()){
            TreeNode *x=q.front();
            q.pop();
            if(x==NULL){
                str+="#,";
            }
            else{
                str=str+(to_string(x->val))+",";
            }
            if(x!=NULL){
                q.push(x->left);
                q.push(x->right);
            }
        }
        cout<<str;
        return str;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        string str;
        getline(s,str,',');
        if(str=="#") return NULL;
        TreeNode *root=new TreeNode(stoi(str));
        queue <TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *x=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                x->left=NULL;
            }
            else{
                TreeNode *temp=new TreeNode(stoi(str));
                x->left=temp;
                q.push(temp);
            }
            getline(s,str,',');
            if(str=="#"){
                x->right=NULL;
            }
            else{
                TreeNode *temp=new TreeNode(stoi(str));
                x->right=temp;
                q.push(temp);
            }
            
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));