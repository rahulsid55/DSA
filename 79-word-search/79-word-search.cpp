
class Solution {
public:
    
    bool dfs(string word,int x,int y,vector<vector<char>>& board,int n,int m,int len,int h[],int v[])
    {
       if(len==word.length()){
           return true;
       } 
       for(int i=0;i<4;i++){
           int X=x+h[i];
           int Y=y+v[i];
           
           if(X>=0 and Y>=0 and X<n and Y<m and board[X][Y]==word[len]){
               //cout<<X<<" "<<Y<<endl;
               char c=board[X][Y];
               board[X][Y]='-';
               if(dfs(word,X,Y,board,n,m,len+1,h,v)==true)
                   return true;
               board[X][Y]=c;
           }
           
       }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        int h[4]={0,0,1,-1};
        int v[4]={1,-1,0,0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0]){
                    char c=board[i][j];
                    board[i][j]='-';
                    if(dfs(word,i,j,board,n,m,1,h,v)==true)
                        return true;
                    board[i][j]=c;
                    
                }
            }
        }
        return false;
        
        
    }
};