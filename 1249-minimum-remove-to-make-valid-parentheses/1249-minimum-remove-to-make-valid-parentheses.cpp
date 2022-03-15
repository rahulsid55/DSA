class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        int l=0,r=n-1;
        int open=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') open++;
            if(s[i]==')') if(open>0){
                open--;
            }
            else
                s[i]='*';
        }
        open=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==')') open++;
            if(s[i]=='(') if(open>0){
                open--;
            }
            else
                s[i]='*';
        }
        
       string ans="";
        for(int i=0;i<n;i++)
        {
            if(s[i]!='*')
                ans+=s[i];
        }
        return ans;
        
    }
};