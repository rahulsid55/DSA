class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        int len,maxlen=0,start=0,end=0;
        int i,j,k=0;
       while(k<n)
       {
           i=0;
           j=k;
           while(i<n && j<n)
           {
               if(j==i)
               {
                   dp[i][j]=1;
                   if(maxlen<1)
                   {
                       maxlen=1;
                       start=i;
                   }
               }
               else if((j-i)==1)
               {
                   if(s[j]==s[i])
                   {
                       dp[i][j]=1;
                       if(maxlen<2)
                       {
                           maxlen=2;
                           start=i;
                       }
                   }
               }
               else
               {
                   if(s[i]==s[j] && dp[i+1][j-1]==1)
                   {
                       len=j-i+1;
                       dp[i][j]=1;
                       if(maxlen<len)
                       {
                           maxlen=len;
                           start=i;
                       }
                   }
               }
               i++;j++;
           }
                
           k++;     
        }
        
      return s.substr(start,maxlen);  
    }
};