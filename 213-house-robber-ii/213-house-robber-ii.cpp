class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int inc[n],exe[n];
        inc[0]=nums[0];
        exe[0]=0;
        if(n==1) return nums[0];
        for(int i=1;i<n-1;i++)
        {
            inc[i]=nums[i]+exe[i-1];
            exe[i]=max(inc[i-1],exe[i-1]);
        }
        int ans1=max(inc[n-2],exe[n-2]);
        inc[0]=0;exe[0]=0;
        inc[1]=nums[1];
        exe[1]=0;
         for(int i=2;i<n;i++)
        {
            inc[i]=nums[i]+exe[i-1];
            exe[i]=max(inc[i-1],exe[i-1]);
        }
        int ans2=max(inc[n-1],exe[n-1]);
        return max(ans1,ans2);
    }
};