class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366,0);
        set<int> s;
        for(auto it: days){
            s.insert(it);
        }
        for(int i=1;i<=365;i++){
            if(s.find(i)==s.end()){
                dp[i]=dp[i-1];
                continue;
            }
            int a=dp[i-1]+costs[0];
            int b=dp[max(i-7,0)]+costs[1];
            int c=dp[max(i-30,0)]+costs[2];
            dp[i]=min({a,b,c});
            //cout<<dp[i]<<" ";
        }
        return dp[365];
        
    }
};