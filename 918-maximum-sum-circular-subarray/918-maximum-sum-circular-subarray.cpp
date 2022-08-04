class Solution {
public:
    int kadane(vector<int> nums){
        int sum=nums[0],max_so_far=nums[0];
        for(int i=1;i<nums.size();i++){
            sum=max(nums[i],sum+nums[i]);
            max_so_far=max(sum,max_so_far);
        }
        return max_so_far;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans1=kadane(nums);
        int sum=0;
        int n=nums.size();
        int flag=0;
        for(auto it: nums){
            if(it>0) flag=1;
            sum+=it;
        }
        if(flag==0) return ans1;
        for(int i=0;i<n;i++) nums[i]=-nums[i];
        int ans2=sum-(-kadane(nums));
        return max(ans1,ans2);
        
    }
};