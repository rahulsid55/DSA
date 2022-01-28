class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groups) {
        int n=groups.size();
        map<int,int> mp;
        int visited[n];
        memset(visited,0,sizeof(visited));
        for(int i=0;i<n;i++){
            mp[groups[i]]+=1;
        }
        vector<vector<int>> ans;
        for(auto i: mp){
            int x=i.second/i.first;
            
            for(int j=0;j<x;j++){
                vector<int> temp;
                int y=i.first;
                for(int k=0;k<n;k++){
                    if(groups[k]==i.first and visited[k]==0 and y--){
                        //cout<<k<<" "<<i.first<<endl;
                        temp.push_back(k);
                        visited[k]=1;
                    }
                    if(y==0) break;
                }
                ans.push_back(temp);
            }
            
        }
        return ans;
    }
};