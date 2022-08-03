class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                st.push({s[i],1});
            }
            else{
                if(st.top().first==s[i]){
                    if(st.top().second==k-1){
                        st.pop();
                    }
                    else{
                        st.top().second+=1;
                        cout<<i<<" ";
                    }
                }
                else{
                    st.push({s[i],1});
                }
            }
        }
        string ans="";
        while(!st.empty()){
            while(st.top().second--)
              ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};