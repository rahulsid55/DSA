class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0) return 0;
        int left[n],right[n];
        left[0]=height[0];
        for(int i=1;i<n;i++)
        {
            int x=max(height[i-1],left[i-1]);
            left[i]=max(x,height[i]);
        }
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            int x=max(height[i+1],right[i+1]);
            right[i]=max(x,height[i]);
        }
        int ct=0;
        for(int i=0;i<n;i++)
        {
            ct+=min(left[i],right[i])-height[i];
        }
        return ct;
        
    }
};