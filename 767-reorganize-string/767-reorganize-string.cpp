class Solution {
public:
    string reorganizeString(string s) {
        string ans="";
        int n=s.length();
        map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
            ans+='$';
        }
        priority_queue<pair<int,char>> pq;
        for(auto it: mp){
            pq.push({it.second,it.first});
        }
        int i=0;
        while(!pq.empty()){
            char c=pq.top().second;
            int len=pq.top().first;
            pq.pop();
            while(len--){
                if(ans[1]=='$'){
                    if(n%2){
                        if(i==n+1){
                            i=1;
                        }
                    }
                    else{
                        if(i==n){
                            i=1;
                        }
                    }
                }
                ans[i]=c;
                if(i>0 and ans[i]==ans[i-1]) return "";
                i+=2;
            }
        }
        return ans;
        
    }
};