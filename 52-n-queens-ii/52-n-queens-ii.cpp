class Solution {
public:
    int ans=0;
    bool isSafe(vector<vector<char>> &board,int row,int col,int n){
        //left diagnol up
        int x=row-1,y=col-1;
        while(x>=0 and y>=0){
            if(board[x][y]=='Q') return false;
            x--;y--;
        }
        //right diag up
        x=row-1;y=col+1;
        while(x>=0 and y<n){
            if(board[x][y]=='Q') return false;
            x--;
            y++;
        }
        //right diag below
        x=row+1;y=col+1;
        while(x<n and y<n){
            if(board[x][y]=='Q') return false;
            x++;
            y++;
        }
        //lef diag below
        x=row+1;y=col-1;
        while(x<n and y>=0){
            if(board[x][y]=='Q') return false;
            x++;
            y--;
        }
        x=row-1;
        while(x>=0){
            if(board[x][col]=='Q') return false;
            x--;
        }
        return true;
        
        
    }
bool ispossible(int row,vector<vector<char>> &board,int n){
    if(row>=n){
     ans++;
    return true;
    }
    for(int i=0;i<n;i++){
        board[row][i]='Q';
        isSafe(board,row,i,n) and ispossible(row+1,board,n);
        board[row][i]='.';
    }
        return false;
}
    int totalNQueens(int n) {
        vector<vector<char>> board(n,vector<char> (n,'.'));
        for(int i=0;i<n;i++){
          
            board[0][i]='Q';
            ispossible(1,board,n);
            board[0][i]='.';
        }
        return ans;
        
    }
};