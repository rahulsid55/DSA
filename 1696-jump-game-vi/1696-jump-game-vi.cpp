class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        int dp[n];
        dp[n-1]=nums[n-1];
        deque <int> dq;
        dq.push_back(n-1);
        int sum=0;
        for(int i=n-2;i>=0;i--){
            if(dq.front()-i>k) dq.pop_front();
            dp[i]=nums[i]+dp[dq.front()];
            while(dq.size() and dp[dq.back()]<dp[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return dp[0];
        
    }
};