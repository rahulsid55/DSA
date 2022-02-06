class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int count[n];
        memset(count,0,sizeof(count));
        if(n<3) return 0;
        int i=2;
        while(i<n){
            if(2*nums[i-1]==nums[i]+nums[i-2]){
                count[i]=1;
                int diff=nums[i]-nums[i-1];
                i=i+1;
                while(i<n){
                    if(nums[i]-nums[i-1]==diff){
                        count[i]=1+count[i-1];
                        i++;
                    }
                    else{
                        i++;
                        break;
                    }
                }
            }
            else{
                i++;
            }
            
        }
        int ans=0;
        for(int i=0;i<n;i++)
            ans+=count[i];
    return ans;
    }
};