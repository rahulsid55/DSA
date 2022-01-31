class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n+1];
        dp[1]=1;
        int two=1,three=1,five=1;
        for(int i=2;i<=n;i++){
            int n1=2*dp[two];
            int n2=3*dp[three];
            int n3=5*dp[five];
            int ans=min(n1,min(n2,n3));
            dp[i]=ans;
            if(ans==n1 ) two++;
            if(ans==n2) three++;
            if(ans==n3) five++;
            //cout<<ans<<" ";
        }
        return dp[n];
    }
};