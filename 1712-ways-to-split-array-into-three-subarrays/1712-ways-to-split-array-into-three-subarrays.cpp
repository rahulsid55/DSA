class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            nums[i]=nums[i]+nums[i-1];
        }
        int count=0,n=nums.size();
        for(int i=0;i<n-1;i++){
            int l=lower_bound(nums.begin()+i+1,nums.end()-1,2*nums[i])-nums.begin();
            int u=upper_bound(nums.begin()+i+1,nums.end()-1,(nums.back()+nums[i])/2)-nums.begin();
            count=(count+max(0,(u-l)))%1000000007;
        }
        return count;
        
    }
};