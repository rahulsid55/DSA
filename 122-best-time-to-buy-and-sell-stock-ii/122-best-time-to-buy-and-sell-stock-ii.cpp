class Solution {
public:
    int solve(int ind,int buy,int dp[][2],vector<int> &prices){
        if(ind==prices.size()){
            return dp[ind][buy]=0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            dp[ind][buy]=max(-1*prices[ind]+solve(ind+1,1-buy,dp,prices),solve(ind+1,buy,dp,prices));
        }
        else{
            dp[ind][buy]=max(prices[ind]+solve(ind+1,1-buy,dp,prices),solve(ind+1,buy,dp,prices));
        }
        return dp[ind][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int dp[n+1][2];
        memset(dp,-1,sizeof(dp));
        return solve(0,1,dp,prices);
        
    }
};