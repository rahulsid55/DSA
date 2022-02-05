class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        int dp[n][2];
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                dp[i][j]=1;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    dp[i][0]=max(dp[i][0],1+dp[j][1]);
                }
                else if(nums[i]<nums[j]){
                    dp[i][1]=max(dp[i][1],1+dp[j][0]);
                }
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                maxi=max(dp[i][j],maxi);
            }
        }
        return maxi;
        
    }
};