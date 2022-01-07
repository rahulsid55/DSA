class Solution {
public:
    string shortestPalindrome(string s) {
        
        string rev_s=s;
        reverse(rev_s.begin(),rev_s.end());
        string res=s+"#"+rev_s;
        int n=res.length();
        int pat[n];
        for(int i=0;i<n;i++){
            pat[i]=0;
        }
        for(int i=1;i<n;i++){
            int j=pat[i-1];
            //cout<<j<<" ";
            while(j>0 and res[i]!=res[j]){
                j=pat[j-1];
            }
            if(res[i]==res[j])
            {
                pat[i]=1+j;
            }
        }
        int trim=pat[n-1];
        rev_s.erase(rev_s.length()-trim);
        
        return rev_s+s;
        
    }
};