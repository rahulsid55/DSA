class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]=i;
        }
        int visited[26]={0};
        stack<char> st;
        for(int i=0;i<s.length();i++){
           while(!st.empty() and visited[s[i]-'a']==0 and st.top()>s[i] and i<mp[st.top()]){
               visited[st.top()-'a']=0;
               //cout<<st.top()<<" "<<i<<endl;
               st.pop();
           }
            if(visited[s[i]-'a']==0){
            st.push(s[i]);
            visited[st.top()-'a']=1;
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};