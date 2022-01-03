bool compare(string a ,string b)
    {
        return a.size()>b.size();
    }
class Solution {
public:
    bool ispred(string a,string b)
    {
        if(b.length()<a.length()){
            ispred(b,a);
        }
        for(int i=0;i<b.length();i++){
            string temp=b;
            temp.erase(i,1);
            if(temp==a)
                return true;
        }
        return false;
        
    }
    
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        
        sort(words.begin(),words.end(),compare);
        map <string,int> dp;
        for(auto u : words){
            dp[u]=1;
        }
        for(auto u:words){
            for(int i=0;i<u.length();i++){
                string temp=u;
                temp.erase(i,1);
                dp[temp]=max(dp[temp],1+dp[u]);
            }
        }
        int ans=0;
        for(auto u:words){
            ans=max(dp[u],ans);
        }
        return ans;
        
    }
};