class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        long long int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        int sz=primes.size();
        int ct[sz];
        for(int i=0;i<sz;i++){
            ct[i]=1;
        }
        
        for(int j=2;j<=n;j++){
            dp[j]=INT_MAX;
            for(int k=0;k<sz;k++){
                //cout<<ct[k]<<" ";
                dp[j]=min(dp[ct[k]]*primes[k],dp[j]);
                //cout<<dp[j]<<" ";
            }
            for(int k=0;k<sz;k++){
                if(dp[j]==dp[ct[k]]*primes[k]){
                    ct[k]++;
                }
            }
        }
        return dp[n];
    }
};