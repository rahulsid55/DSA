class Solution {
public:
    int dp[21][21];
    int solve(vector<int> nums,int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int a=nums[i]+min(solve(nums,i+2,j),solve(nums,i+1,j-1));
        int b=nums[j]+min(solve(nums,i,j-2),solve(nums,i+1,j-1));
        return dp[i][j]=max(a,b);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int sum=0;
        memset(dp,-1,sizeof(dp));
        for(auto it: nums){
            sum+=it;
        }
        int play1=solve(nums,0,nums.size()-1);
        if(sum-play1<=play1) return true;
        return false;
        
    }
};