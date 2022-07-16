class Solution {
public:
    int solve(vector<int> &arr,int i,int k,vector<int> &dp){
        int n=arr.size();
        if(i==arr.size()) return 0;
        int cnt=0,maxi=0,len=0;
        if(dp[i]!=-1) return dp[i];
        for(int j=i;j<min(i+k,n);j++){
            len++;
            maxi=max(maxi,arr[j]);
            
            cnt=max(cnt,(maxi*len)+solve(arr,j+1,k,dp));
        }
        return dp[i]=cnt;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return solve(arr,0,k,dp);
        
    }
};