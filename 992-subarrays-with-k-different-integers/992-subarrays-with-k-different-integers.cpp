class Solution {
public:
    int help(vector<int> &nums,int k){
        map<int,int> mp;
        int j=0,ct=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            while( mp.size()>k){
                if(mp[nums[j]]>1){
                    mp[nums[j]]--;
                }
                else{
                    mp.erase(nums[j]);
                }
                j++;
            }
            ct+=(i-j+1);
        }
        cout<<ct;
        return ct;
        
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return help(nums,k)-help(nums,k-1);
    }
};