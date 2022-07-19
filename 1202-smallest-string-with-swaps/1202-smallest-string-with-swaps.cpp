class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int findpar(int a){
        while(parent[a]!=a){
            parent[a]=parent[parent[a]];
            a=parent[a];
        }
        return a;
    }
    void unionOf(int a,int b){
        int par1=findpar(a);
        int par2=findpar(b);
        if(par1!=par2)
            parent[par1]=par2;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
       int n=s.length();
       parent.resize(n);
        rank.resize(n,0);
       for(int i=0;i<n;i++){
           parent[i]=i;
       }
        for(auto it:pairs){
            unionOf(it[0],it[1]);
        }
        map<int,string> mp;
        map<int,int> index;
        cout<<1;
        for(int i=0;i<n;i++){
            int par=findpar(i);
            if(!mp.count(par)){
                mp[par]="";
            }
            mp[par].push_back(s[i]);
        }
        for(auto &it: mp){
             sort(it.second.begin(),it.second.end());
             index[it.first]=0;
            
        }
        string ans="";
        for(int i=0;i<n;i++){
            int par=findpar(i);
            ans+=(mp[par][index[par]++]);
        }
        return ans;
        
    }
};