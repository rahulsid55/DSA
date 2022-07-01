class Solution {
    int const mod=1e9+7;
public:
    int countTexts(string keys) {
        int n=keys.size();
        int dp[n+1];
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            if(i-2>=0 and keys[i-1]==keys[i-2]) dp[i]=(dp[i]+dp[i-2])%mod;
            else continue;
            if(i-3>=0 and keys[i-1]==keys[i-3]) dp[i]=(dp[i]+dp[i-3])%mod;
            else continue;
            if((keys[i-1]=='7' or keys[i-1]=='9') and i-4>=0 and keys[i-1]==keys[i-4]) dp[i]=(dp[i]+dp[i-4])%mod;
        }
        return dp[n];
    }
};