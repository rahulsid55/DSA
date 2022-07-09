class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        map<int,int> mp;
        int ans=1,j=0,i=0;
        while(i<n){
            mp[nums[i]]++;
            //cout<<mp.size()<<" ";
            if(abs(mp.rbegin()->first - mp.begin()->first) <= limit)
            {
                ans = max(ans, i-j+1);
            }
            else{
            while(i>j and abs(mp.rbegin()->first - mp.begin()->first)>limit){
                    mp[nums[j]]--;
                    if(mp[nums[j]]==0) mp.erase(nums[j]);
                    j++;
                }
            }
            //ans=max(ans,i-j+1);
            //cout<<mp.size()<<endl;
            i++;
            
        }
        //ans=max(ans,i-j+1);
    return ans;
    }
};