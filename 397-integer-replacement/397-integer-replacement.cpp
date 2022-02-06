class Solution {
public:
    unordered_map<long long int,long long int> dp;
    long long  helper(long long n){
        if(n==1) return dp[n]=0;
        if(dp.count(n)){
            return dp[n];
        }
        if(n%2==0) {
            dp[n]=1+helper(n/2);
        }
        else{
            dp[n]=1+min(helper(n-1),helper(n+1));
        }
        return dp[n];
    }
    int integerReplacement(int n) {
        long long  ans=helper(n);
        return ans;
    }
};