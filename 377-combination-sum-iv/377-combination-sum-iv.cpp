class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unsigned int dp[target+1];
        //return 0;
        dp[0]=1;
        for(int i=1;i<=target;i++){
            dp[i]=-1;
        }

        sort(nums.begin(),nums.end());
        for(int i=1;i<=target;i++){
            for(int j=0;j<nums.size();j++){
                if(i>=nums[j]){
                    if(dp[i-nums[j]]!=-1){
                        if(dp[i]==-1){
                            dp[i]=dp[i-nums[j]];
                        }
                        else{
                            dp[i]=dp[i]+dp[i-nums[j]];
                        }
                    }
                }
                else{
                    break;
                }
            }
        }
        return dp[target]==-1?0:dp[target];
    }
};