class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),target;
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++)
        {
            if(i==0 || nums[i]!=nums[i-1])
            {
            int j=i+1;
            int k=n-1;
            
            while(j<k)
            {
                 target=nums[i]+nums[j]+nums[k];
                if(target==0)
                {
                    
                    ans.insert(ans.end(),{nums[i],nums[j],nums[k]});
                    j++;k--;
                    while(j<k && nums[j]==nums[j-1])
                    {
                        j++;
                    }
                
                }
                else if(target>0)
                {
                        k--;
                }
                else
                {
                   j++;
                }
                
            }
        }
            
        }
        return ans;
        
        
    }
};