class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        int dp[n][m][k+1];
        memset(dp,0,sizeof(dp));
        int steps=0;
        queue<vector<int>> q;
        q.push({0,0,k});
        dp[0][0][k]=1;
        int dx[5]={0,1,0,-1,0};
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                vector<int> temp=q.front();
                q.pop();
                int x=temp[0];
                int y=temp[1];
                int K=temp[2];
                if(x==n-1 and y==m-1) return steps;
                
                for(int i=0;i<4;i++){
                    int X=x+dx[i];
                    int Y=y+dx[i+1];
                    if(X>=0 and Y>=0 and X<n and Y<m){
                        if(grid[x][y]==1){
                            if(K>0 and dp[X][Y][K-1]==0){
                                q.push({X,Y,K-1});
                                dp[X][Y][K-1]=1;
                            }
                        }
                        else{
                            if(dp[X][Y][K]==0)
                            q.push({X,Y,K});
                            dp[X][Y][K]=1;
                        }
                    }
                }
            }
            steps++;
            
        }
        return -1;
    }
};