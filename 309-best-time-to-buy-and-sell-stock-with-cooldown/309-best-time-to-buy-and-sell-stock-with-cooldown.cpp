class Solution {
    vector<vector<vector<int>>> dp;
    int recursion(vector<int> prices,int pos,bool cool,bool bought)
    {
        
        if(prices.size()<=pos) return 0;
        if(dp[bought][cool][pos]!=-1) return dp[bought][cool][pos];
        if(bought)
        {
dp[bought][cool][pos]=max(prices[pos]+recursion(prices,pos+1,!cool,!bought),recursion(prices,pos+1,cool,bought));
        }
        else
        {
            if(cool)
            {
                dp[bought][cool][pos]=recursion(prices,pos+1,!cool,bought);
            }
            else
            {
dp[bought][cool][pos]=max(-1*prices[pos]+recursion(prices,pos+1,cool,!bought),recursion(prices,pos+1,cool,bought));
            }
        }
        
        return dp[bought][cool][pos];
    }
    
public:
    int maxProfit(vector<int>& prices) {
        dp.resize(2,vector<vector<int>>(2,vector<int>(prices.size(),-1)));
        return recursion(prices,0,false,false);
    }
};