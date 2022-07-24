class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        int n=nums.size();
        while(l<=r){
            int mid=(l+r)/2;
            if(mid+1<n and nums[mid]>nums[mid+1]) return nums[mid+1];
            if(mid-1>=0 and nums[mid]<nums[mid-1]) return nums[mid];
            if(nums[mid]>nums[l]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return nums[0];
        
    }
};