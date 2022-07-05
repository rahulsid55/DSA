class Solution {
public:
    int solve(int idx,int dp[][2][3],vector<int> &prices,int buy,int cap){
        if(idx==prices.size()) return dp[idx][buy][cap]=0;
        if(cap==0) return dp[idx][buy][cap]=0;
        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
        if(buy){
            int a=-prices[idx]+solve(idx+1,dp,prices,1-buy,cap);
            int b=solve(idx+1,dp,prices,buy,cap);
            return dp[idx][buy][cap]=max(a,b);
        }
        else{
            int a=prices[idx]+solve(idx+1,dp,prices,1-buy,cap-1);
            int b=solve(idx+1,dp,prices,buy,cap);
            return dp[idx][buy][cap]=max(a,b);
        }
        return dp[idx][buy][cap];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int dp[n+1][2][3];
        memset(dp,-1,sizeof(dp));
        return solve(0,dp,prices,1,2);
        
    }
};