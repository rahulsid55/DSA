// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
   public:
    unordered_set<string> mp;
    unordered_map<int,bool> mem;
    bool helper(string A,int pos,int n){
        if(pos>=n) return mem[pos]=true;
        if(mem.count(pos)) return mem[pos];
        for(int i=pos;i<n;i++){
            if(mp.count(A.substr(pos,i-pos+1)) and helper(A,i+1,n)){
                return mem[pos]=true;
            }
        }
        return mem[pos]=false;
    }
    int wordBreak(string A, vector<string> &B) {
        int n=A.length();
        for(auto i: B){
            mp.insert(i);
        }
        
        return helper(A,0,A.length());
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends