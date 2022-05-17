// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    int i=0,j=0,n=s.length(),ans=0;
    map<char,int> mp;
    while(j<n){
        if(mp.find(s[j])!=mp.end()){
            //cout<<i<<" "<<j<<endl;
            ans=max(ans,j-i);
            i=max(i,mp[s[j]]+1);
            
        }
        mp[s[j]]=j;
        j++;
    }
    ans=max(ans,j-i);
    return ans;
}