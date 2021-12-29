class Solution {
    int lpalindromesub(string s){
        int n=s.length(),j;
        int dp[n][n];
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        for(int l=2;l<=n;l++)
        {
            for(int i=0;i<n-l+1;i++)
            {
                j=i+l-1;
                if(s[i]==s[j] and l==2)
                {
                    dp[i][j]=2;
                }
                else if(s[i]==s[j])
                {
                    dp[i][j]=2+dp[i+1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
public:
    int minInsertions(string s) {
        int x=lpalindromesub(s);
        cout<<x;
        int n=s.length();
        return n-x;
    }
};