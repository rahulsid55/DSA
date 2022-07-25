class Solution {
public:
    map<string,int> mp;
    int invalid(string s){
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')'){
                if(!st.empty() and st.top()=='('){
                    st.pop();
                }
                else{
                    st.push(')');
                }
            }
        }
        return st.size();
    }
    void findall(vector<string> &ans,string s,int cnt){
        //cout<<s<<endl;
        if(mp[s]!=0) return;
        mp[s]++;
        if(cnt<0) return;
        if(cnt==0){
            if(invalid(s)==0){
            ans.push_back(s);
            }
        return;
        }
        for(int k=0;k<s.length();k++){
                string left=s.substr(0,k);
                string right=s.substr(k+1);
                findall(ans,left+right,cnt-1);
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int cnt=invalid(s);
        vector<string> ans;
        findall(ans,s,cnt);
        return ans;
    }
};