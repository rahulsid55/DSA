class node{
    public:
    char c;
    node *alpha[26];
    string word;
    int end;
    node(char x){
        c=x;
        for(int i=0;i<26;i++){
            alpha[i]=NULL;
        }
        end=0;
        word="";
    }
};
class Solution {
public:
    int visited[20][20];
    int dx[5]={0,1,0,-1,0};
     vector<string> ans;
    node *root=new node('/');
    void insert(string x){
        int n=x.length();
        node *temp=root;
        for(int i=0;i<n;i++){
            if(temp->alpha[x[i]-'a']==NULL){
                temp->alpha[x[i]-'a']=new node(x[i]);
            }
            temp=temp->alpha[x[i]-'a'];
        }
        temp->end+=1;
        temp->word=x;
    }
    void dfs(int x,int y,int n,int m,vector<vector<char>>& board,node *curr){
        int index=board[x][y]-'a';
        //cout<<board[x][y]<<" ";
        if(board[x][y]=='$' || curr->alpha[index]==NULL) return;
        
        char ch=board[x][y];
        board[x][y]='$';
        curr=curr->alpha[index];
        if(curr->end>0){
            ans.push_back(curr->word);
            curr->end-=1;
        }
        if(x-1>=0)
            dfs(x-1,y,n,m,board,curr);
        if(y-1>=0)
            dfs(x,y-1,n,m,board,curr);
        if(x+1<n)
            dfs(x+1,y,n,m,board,curr);
        if(y+1<m)
            dfs(x,y+1,n,m,board,curr);
        board[x][y]=ch;
        
    }
    
        bool search(string word) {
        int n=word.length();
        node *temp=root;
        for(int i=0;i<n;i++){
            if(temp->alpha[word[i]-'a']==NULL){
                return false;
            }
            temp=temp->alpha[word[i]-'a'];
        }
        return temp->end;
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       
        int n=board.size(),m=board[0].size();
        for(auto it: words){
            insert(it);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 dfs(i,j,n,m,board,root);
                //cout<<endl;
            }
        }
        return ans;
        
    }
};