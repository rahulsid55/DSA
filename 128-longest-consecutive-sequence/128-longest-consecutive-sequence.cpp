class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++)
        {
           s.insert(nums[i]); 
        }
        int maxx=0;
        for(int i=0;i<nums.size();i++)
        {
            int ct=0;
            if(s.find(nums[i]-1)!=s.end())
            {
                continue;
            }
            else
            {
                int x=nums[i];
                while(s.find(x)!=s.end())
                {
                    ct++;
                    x++;
                }
                maxx=max(maxx,ct);
            }
        }
          return maxx;  
        }
};