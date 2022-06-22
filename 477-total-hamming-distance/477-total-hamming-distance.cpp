class Solution {
public:
    bool isset(int n,int i){
        if(n & 1<<i){
            return true;
        }
        return false;
    }
    int totalHammingDistance(vector<int>& nums) {
        int ans=0,n=nums.size(),temp[32]={0};
        for(int i=0;i<n;i++){
            for(int j=0;j<32;j++){
                if(isset(nums[i],j)){
                    temp[j]++;
                }
            }
        }
        
        for(int j=0;j<32;j++){
            ans+=(temp[j]*(n-temp[j]));
        }
        return ans;
        
    }
};