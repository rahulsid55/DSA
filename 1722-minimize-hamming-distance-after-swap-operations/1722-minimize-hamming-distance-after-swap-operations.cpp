class Solution {
public:
    vector<int> parent;
    int findpar(int a){
        while(a!=parent[a]){
            parent[a]=parent[parent[a]];
            a=parent[a];
        }
        return a;
    }
    void join(int a,int b){
        int par1=findpar(a);
        int par2=findpar(b);
        if(par1!=par2){
            parent[par2]=par1;
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        for(auto it: allowedSwaps){
            join(it[0],it[1]);
        }
        map<int,map<int,int>> mp;
        for(int i=0;i<n;i++){
            int par=findpar(i);
            mp[par][source[i]]++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            int par=findpar(i);
            if(mp[par].count(target[i]) and mp[par][target[i]]>0){
                mp[par][target[i]]--;
            }
            else{
                count++;
            }
        }
        return count;
    }
};