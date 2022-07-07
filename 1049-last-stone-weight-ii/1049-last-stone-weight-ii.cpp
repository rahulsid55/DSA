class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0,n=stones.size();
        for(auto i: stones){
            sum+=i;
        }
        bool dp[n+1][sum+1];
        memset(dp,false,sizeof(dp));
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(stones[i-1]<=j){
                    dp[i][j]=(dp[i-1][j] || dp[i-1][j-stones[i-1]]); 
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<=sum;i++){
            if(dp[n][i]){
                mini=min(mini,abs(sum-2*i));
            }
        }
        return mini;
        
        
    }
};