class Solution {
public:
    vector<int> dr,dc;
    int n,m;
    
    bool isGood(int r, int c){
        return (r>=0 && r<n && c>=0 && c<m);
    }
    
    bool dfs(vector<vector<char>>& board, int r, int c){
        bool res=true;
        board[r][c]='I';
        for (int i=0; i<4; i++){
            int r2=r+dr[i];
            int c2=c+dc[i];
            if (isGood(r2,c2)){
                if (board[r2][c2]=='O'){
                    res=min(res,dfs(board,r2,c2));    
                }
            } else {
                res=false;
            }
        }
        return res;
    }
    
    void dfs2(vector<vector<char>>& board, int r, int c){
        board[r][c]='X';
        for (int i=0; i<4; i++){
            int r2=r+dr[i];
            int c2=c+dc[i];
            if (isGood(r2,c2) && board[r2][c2]=='I'){
                dfs2(board,r2,c2);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        dr=vector<int>({-1,0,0,1});
        dc=vector<int>({0,-1,1,0});
        // dfs
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (board[i][j]=='O'){
                    bool isSurroundedRegion=dfs(board,i,j);
                    if (isSurroundedRegion){
                        // capture this region
                        dfs2(board,i,j);
                    }
                }
            }
        }
        // restore those unsurrounded regions
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                board[i][j]=(board[i][j]=='I' ? 'O' : board[i][j]);
            }
        }
    }
};