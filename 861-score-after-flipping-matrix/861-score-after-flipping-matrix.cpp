class Solution {
public:
    void toggle(vector<vector<int>> &grid,int k,int n){
    for(int i=0;i<n;i++){
        grid[k][i]=1-grid[k][i];
    }
}
void coltoggle(vector<vector<int>> &grid,int j,int m){
    for(int i=0;i<m;i++) grid[i][j]=1-grid[i][j];
}
int count(vector<vector<int>> &grid,int k,int x,int m){
    int cnt=0;
    for(int i=0;i<m;i++){
        if(grid[i][k]==x){
            cnt++;
        }
    }
    return cnt;
}
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
    for(int i=0;i<m;i++){
        if(grid[i][0]==0){
            toggle(grid,i,n);
        }
    }
    for(int i=0;i<n;i++){
        if(count(grid,i,0,m)>count(grid,i,1,m)){
            coltoggle(grid,i,m);
        }
    }
    int ans=0;
    for(int i=0;i<m;i++){
        int temp=0,x=1;
        for(int j=n-1;j>=0;j--){
            temp+=grid[i][j]*x;
            x=x*2;
        }
        ans+=temp;
        
    }
    return ans;
        
    }
};