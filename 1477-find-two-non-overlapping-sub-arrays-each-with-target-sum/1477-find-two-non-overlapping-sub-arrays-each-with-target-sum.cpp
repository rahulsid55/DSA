class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        int i=n-1,j=n-1,sum=0,ans=INT_MAX;
        while(i>=0){
            sum+=arr[i];
            //cout<<sum<<" ";
            while(sum>target) sum-=arr[j--];
            if(sum==target){
                dp[i]=j-i+1;
                if(dp[i+1]!=-1 and dp[i+1]<dp[i]){
                    dp[i]=dp[i+1];
                }
                if(dp[j+1]!=-1){
                    ans=min(ans,j-i+1+dp[j+1]);
                }
            }
            else{
                dp[i]=dp[i+1];
            }
            i--;
        }
        return ans==INT_MAX?-1:ans;
    }
};