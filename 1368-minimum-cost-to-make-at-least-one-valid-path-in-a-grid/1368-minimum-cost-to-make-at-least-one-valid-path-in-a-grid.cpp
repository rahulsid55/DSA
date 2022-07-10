class Solution {
public:
    int dp[301][301];
    bool verify(int i,int j,int m,int n){
        if(i<0 || j<0 || i>=m || j>=n) return false;
        return true; 
    }
    int minCost(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=100000;
            }
        }
        q.push({0,0});
        dp[0][0]=0;
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        while(!q.empty()){
            pair <int,int> temp=q.front();
            q.pop();
            int x=temp.first,y=temp.second;
            //ut<<x<<" "<<endl;
            for(int i=0;i<4;i++){
                int X=x+dx[i];
                int Y=y+dy[i];
                if(verify(X,Y,m,n)){
                    if(i+1==grid[x][y] and dp[X][Y]>dp[x][y]){
                        dp[X][Y]=dp[x][y];
                        q.push({X,Y});
                    }
                    else if(1+dp[x][y]<dp[X][Y]){
                        dp[X][Y]=1+dp[x][y];
                        q.push({X,Y});
                    }
                }
            }
        }
        return dp[m-1][n-1];
        
    }
};