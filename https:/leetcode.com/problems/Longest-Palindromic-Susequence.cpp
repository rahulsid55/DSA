class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        int dp[n][n];
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        int i,j,k=1;
        while(k<n)
        {
            i=0;
            j=k;
            while(j<n)
            {
                if(j-i==1)
                {
                    if(s[i]==s[j])
                        dp[i][j]=2;
                    else
                        dp[i][j]=1;
                }
                else if(s[i]==s[j])
                {
                    dp[i][j]=2+dp[i+1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
                //cout<<i<<" "<<j<<endl;
                i++;
                j++;
                
            }
            k++;
        }
        return dp[0][n-1];
        
    }
}
