class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int prefix[n];
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        int ans=0,sum=0,j=0;
         unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(mp.count(nums[i])){
                j=max(mp[nums[i]],j);
                sum=prefix[i]-prefix[j];
            }
            mp[nums[i]]=i;
            ans=max(ans,sum);
        }
        return ans;
        
    }
};