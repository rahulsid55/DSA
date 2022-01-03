class Solution {
    vector<vector<vector<int>>> dp;
    int recursion(vector<int> prices,int pos,bool cool,bool bought)
    {
        
        if(prices.size()<=pos) return 0;
        if(dp[bought][cool][pos]!=-1) return dp[bought][cool][pos];
        int result=recursion(prices,pos+1,cool,bought);
        if(bought)
        {
            result=max(result,recursion(prices,pos+1,true,false)+prices[pos]);
        }
        else
        {
            if(!cool)
            {
                result=max(result,recursion(prices,pos+1,false,true)-prices[pos]);
            }
            else
            {
                result=max(result,recursion(prices,pos+1,false,false));
            }
        }
        
        return dp[bought][cool][pos]=result;
    }
    
public:
    int maxProfit(vector<int>& prices) {
        dp.resize(2,vector<vector<int>>(2,vector<int>(prices.size(),-1)));
        return recursion(prices,0,false,false);
    }
};