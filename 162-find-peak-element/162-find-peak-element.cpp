class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int l=1,r=n;
        nums.push_back(INT_MIN);
        nums.insert(nums.begin(),INT_MIN);
        while(l<=r){
            int mid=(l+r)/2;
            //cout<<nums[mid-1]<<" "<<nums[mid]<<" "<<nums[mid+1]<<endl;
            if(nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1]) return mid-1;
            if(nums[mid]<nums[mid+1]) l=mid+1;
            else r=mid-1;
        }
        return 0;
    }
};