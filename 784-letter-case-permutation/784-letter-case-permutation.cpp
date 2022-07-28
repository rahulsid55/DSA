class Solution {
public:
    void solve(string s,int i,vector<char> &ds,vector<string> &ans){
        if(i==s.length()){
            ans.push_back(s);
            return;
        }
        if(isdigit(s[i])){
            solve(s,i+1,ds,ans);
        }
        else{
            char x=s[i];
            s[i]=x-32;
            solve(s,i+1,ds,ans);
            s[i]=x;
            solve(s,i+1,ds,ans);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<char> ds;
        vector<string> ans;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        solve(s,0,ds,ans);
        return ans;
    }
};