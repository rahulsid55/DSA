/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node *newnode,vector<Node *> &vis,Node *node)
    {
        vis[node->val]=newnode;
        for(auto i: node->neighbors){
            if(vis[i->val]==NULL){
                Node *newnode1=new Node(i->val);
                newnode->neighbors.push_back(newnode1);
                dfs(newnode1,vis,i);
            }
            else
            {
                newnode->neighbors.push_back(vis[i->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node *copy=new Node(node->val);
        vector<Node *> visited(101,NULL);
        visited[node->val]=copy;
        for(auto ele : node->neighbors){
            if(visited[ele->val]==NULL)
            {
                Node *newnode=new Node(ele->val);
                copy->neighbors.push_back(newnode);
                dfs(newnode,visited,ele);
            }
            else
            {
                copy->neighbors.push_back(visited[ele->val]);
            }
        }
        
        return copy;
        
    }
};