class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n=nums.size();
        int ct=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                string temp1=nums[i]+nums[j];
                string temp2=nums[j]+nums[i];
                ct+=(target==temp1)+(target==temp2);
            }
        }
        return ct;
        
    }
};