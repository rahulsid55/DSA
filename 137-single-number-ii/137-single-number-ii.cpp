class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for(int i=0;i<32;i++){
            int ct=0;
            for(int j=0;j<n;j++){
                if(nums[j] & (1<<i)){
                    ct++;
                }
            }
            if(ct%3){
                ans+=(1<<i);
            }
        }
        return ans;
        
    }
};