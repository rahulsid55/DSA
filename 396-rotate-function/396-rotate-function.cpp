class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int maxi=0;
        int x=0;
        for(int i=0;i<n;i++){
            x+=nums[i]*i;
        }
        maxi=x;
        int prev=x;
     
        for(int i=n-1;i>=1;i--){
            int t=sum-nums[i];
            prev=prev-(n-1)*nums[i]+t;
            //cout<<prev<<endl;
            maxi=max(maxi,prev);
            
        }
        return maxi;
        
    }
};