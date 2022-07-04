class Solution {
public:
    map<string,bool> mp;
    bool solve(string s1,string s2){
        if(s1.length()==1){
            return s1==s2;
        }
        if(s1==s2) return true;
        string key=s1+s2;
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }
        vector<int> f1(26),f2(26);
        int n=s1.length();
        for(int i=0;i<n;++i)
        {
            f1[s1[i]-'a']+=1;
            f2[s2[i]-'a']+=1;
        }
        if(f1!=f2)
            return mp[key]=false;
        
        for(int i=1;i<n;i++){
                        if((solve(s1.substr(0,i),s2.substr(0,i)) and solve(s1.substr(i),s2.substr(i)))
               or(solve(s1.substr(0,i),s2.substr(n-i)) and solve(s1.substr(i),s2.substr(0,n-i))))
                return mp[key]=true;
        }
        return mp[key]=false;
    }
    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
        
    }
};