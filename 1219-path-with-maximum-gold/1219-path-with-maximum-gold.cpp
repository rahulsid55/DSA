class Solution {
public:
    int visited[16][16];
    int maxi=0,sum=0;
    vector<int> dx;
    void dfs(int i,int j,int m,int n,vector<vector<int>>& grid){
        
        //cout<<i<<" "<<j<<"*";
        sum+=grid[i][j];
        //cout<<grid[i][j]<<" ";
       maxi=max(maxi,sum);
        visited[i][j]=1;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dx[k+1];
            //cout<<x<<" "<<y<<"*";
            if(x>=0 && y>=0 && x<m && y<n && grid[x][y]>0 && visited[x][y]==0){
                
                   dfs(x,y,m,n,grid);
            }
        }
         
        sum-=grid[i][j];
        visited[i][j]=0;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        memset(visited,0,sizeof(visited));
        dx={0,1,0,-1,0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    //cout<<grid[i][j]<<endl;
                    dfs(i,j,m,n,grid);
                    
                }
            }
        }
        return maxi;
    }
};