// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        string s="",ans="";
        for(int i=0;i<S.length();i++){
            if(S[i]!='.'){
                s+=S[i];
            }
            else{
                ans=s+"."+ans;
                s="";
            }
        }
        
        ans=s+"."+ans;
        ans.pop_back();
        //ans.erase(0,1);
        return ans;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends