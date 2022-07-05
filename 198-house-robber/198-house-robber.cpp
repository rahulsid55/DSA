class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int x,y;
        x=nums[0];
        y=0;
        for(int i=1;i<n;i++)
        {
            int temp=x;
            x=nums[i]+y;
            y=max(temp,y);
            cout<<x<<" "<<y<<endl;
        }
        return max(x,y);
        
    }
};