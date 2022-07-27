class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt=0,j=0,i=0,n=nums.size(),prod=1;;
        while(j<n){
            prod=prod*nums[j];
            while(i<=j and prod>=k){
                prod=prod/nums[i++];
            }
            cnt+=(j-i+1);
            j++;
            
            
        }
       
        return cnt;
    }
};