class Solution {
public:
    void solve(int id,vector<int> nums,vector<int> &ds,vector<vector<int>> &ans)
    {
        if(id==nums.size())
        {
          ans.push_back(nums);
            return;
        }
        for(int i=id;i<nums.size();i++)
        {
          if(i!=id and nums[i]==nums[id]) continue;
            swap(nums[id],nums[i]);
            solve(id+1,nums,ds,ans);
        }
           
            
            
        }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n=nums.size();
        vector<int> ds;
        vector<vector<int>> ans;
       // ans.push_back(nums);
        solve(0,nums,ds,ans);
        return ans;
    }
};