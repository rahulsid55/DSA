class Solution {
public:
    int countOrders(int n) {
        long long dp[n+1];
        dp[0]=0;
        dp[1]=1;
        if(n==1) return 1;
        dp[2]=6;
        for(int i=3;i<=n;i++){
            long long x=((i-1)*2+1)%1000000007;
            x=((x*(x+1)))%1000000007;
            x=x/2;
            dp[i]=(x*dp[i-1])%1000000007;
        }
        return dp[n];
    }
};