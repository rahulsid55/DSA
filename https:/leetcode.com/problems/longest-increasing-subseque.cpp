class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
            {
                ans.push_back(nums[i]);
            }
            else
            {
                int x=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                if(x>=ans.size())
                {
                    ans.push_back(nums[i]);
                }
                else
                 ans[x]=nums[i];
            }
        }
        return ans.size();
    }
};
