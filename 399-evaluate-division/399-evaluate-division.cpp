class Solution {
public:
    void findpath(map<string,vector<pair<string,double>>> &adj,string src,string dest,double &ans,int &flag,set<string> s){
        if(flag==1) return;
        s.insert(src);
        if(src==dest){
            flag=1;
            return;
        }
        //cout<<src<<" ";
        for(auto it: adj[src]){
            if(!s.count(it.first)){
                ans=ans*(it.second);
                if(it.first==dest){
                    flag=1;
                    return;
                }
                findpath(adj,it.first,dest,ans,flag,s);
                if(flag==1){
                    return;
                }
                ans=ans/(it.second);
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        map<string,vector<pair<string,double>>> adj;
        int n=equations.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                adj[equations[i][0]].push_back({equations[i][1],values[i]});
                adj[equations[i][1]].push_back({equations[i][0],1/values[i]});
            }
        }
        vector<double> ans;
        for(int i=0;i<queries.size();i++){
            set <string> s;
            double x=1;
            int flag=0;
            if(!adj.count(queries[i][0]) or !adj.count(queries[i][1])){
                ans.push_back(-1.000000);
                continue;
            }
            findpath(adj,queries[i][0],queries[i][1],x,flag,s);
            if(flag==1)
            ans.push_back(x);
            else{
                ans.push_back(-1.000000);
            }
            //cout<<endl;
        }
        return ans;
        
        
    }
};