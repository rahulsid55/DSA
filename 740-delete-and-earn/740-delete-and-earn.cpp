class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> mp;
        for(auto i : nums){
            mp[i]++;
        }
        
        vector<int> dp(10001,0);
        dp[1]=mp[1];
        for(int i=2;i<10001;i++){
            dp[i]=max(dp[i-2]+mp[i]*i,dp[i-1]);
        }
        return dp[10000];
    }
};