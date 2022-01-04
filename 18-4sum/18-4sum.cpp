class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector <vector<int>> ans1;
        sort(nums.begin(),nums.end());
        int front,back;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                front=j+1;
                back=n-1;
               int target2=target-nums[i]-nums[j];
                while(front<back)
                {
                if(nums[front]+nums[back]>target2)
                {
                    back--;
                }
                else if(nums[front]+nums[back]<target2)
                {
                    front++;
                }
                else
                {
                    vector<int> ans(4,0);
                    ans[0]=nums[front];
                    ans[1]=nums[back];
                    ans[2]=nums[i];
                    ans[3]=nums[j];
                    ans1.push_back(ans);
                    while(front<back && nums[front]==ans[0]) front++;
                    while(front<back && nums[back]==ans[1]) back--;
                }
            }
        while(j+1<n && nums[j+1]==nums[j]) j++;
        }
        while(i+1<n && nums[i+1]==nums[i]) i++;
        }
        return ans1;
    }
};