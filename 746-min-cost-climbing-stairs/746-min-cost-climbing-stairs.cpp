class Solution {
    int solve(vector<int> cost,int i,int dp[])
    {
        if(i>=cost.size())
            return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=cost[i]+min(solve(cost,i+1,dp),solve(cost,i+2,dp));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        return min(solve(cost,0,dp),solve(cost,1,dp));
    }
};