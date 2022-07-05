class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dun) {
        int m=dun.size(),n=dun[0].size();
        int dp[m+1][n+1];
        memset(dp,20001,sizeof(dp));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 and j==n-1){
                    dp[i][j]=dun[i][j]>=0?1:abs(dun[i][j])+1;
                    
                }
                else{
                    dp[i][j]=max(1,min(dp[i+1][j],dp[i][j+1])-dun[i][j]);
                }
            }
        }
        return dp[0][0];
        
    }
};