class Solution {
public:
    int solve(vector<int> &nums,int i,int j,vector<vector<int>> &dp){
        if(i>j){
            return dp[i][j]=0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=INT_MIN;
        for(int k=i;k<=j;k++){
            maxi=max(nums[i-1]*nums[k]*nums[j+1]+solve(nums,i,k-1,dp)+solve(nums,k+1,j,dp),maxi);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        
        return solve(nums,1,n,dp);
        
    }
};