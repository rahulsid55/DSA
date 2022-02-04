class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        pair<int,int> dp[n];
        vector<int> ans;
        for(int i=0;i<n;i++){
            dp[i]={-1,0};
        }
        int maxi=0,idx=0;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    if((dp[j].second+1)>dp[i].second){
                     dp[i]={j,1+dp[j].second};   
                    }
                    
                }
            }
            if(dp[i].second>maxi){
                maxi=dp[i].second;
                idx=i;
            }
        }
        int x=idx;
        while(x!=-1){
            ans.push_back(nums[x]);
            x=dp[x].first;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};