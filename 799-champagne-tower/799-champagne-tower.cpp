class Solution {
public:
    double champagneTower(int poured, int p, int q) {
        double dp[101][101];
        memset(dp,0,sizeof(dp));
        dp[0][0]=poured;
        for(int i=0;i<100;i++){
            //cout<<i<<" ";
            for(int j=0;j<=i;j++){
                if(dp[i][j]>=1){
                    double x=(dp[i][j]-1)/2.0;
                    dp[i][j]=1;
                    dp[i+1][j]+=x;
                    dp[i+1][j+1]+=x;
                }
                //cout<<dp[i][j]<<" ";
                
            }
            //cout<<endl;
        }
        return dp[p][q];
    }
};