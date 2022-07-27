class Solution {
public:
    bool possible(int m,vector<int> nums,int k){
        int l=0,r=m-1;
        
        while(r<nums.size()){
            if(l==0){
                if(m-nums[r]<=k) return true;
            }
            else{
                if(m-(nums[r]-nums[l-1])<=k) return true;
            }
            l++;
            r++;
        }
        return false;
    }
    int longestOnes(vector<int>& nums, int k) {
        for(int i=1;i<nums.size();i++){
            nums[i]=nums[i]+nums[i-1];
        }
        int l=1,r=nums.size(),ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            cout<<l<<" "<<r<<endl;
            if(possible(mid,nums,k)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
        
    }
};