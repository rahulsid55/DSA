class Solution {
public:
    int minSteps(int n) {
        int dp[n+1];
        dp[0]=dp[1]=0;
        for(int i=2;i<=n;i++){
            dp[i]=INT_MAX;
               for(int j=1;j<n;j++){
                   if(i%j==0){
                       dp[i]=min(dp[i],((i-j)/j)+1+dp[j]);
                   }
               }
        }
        return dp[n];
    }
};