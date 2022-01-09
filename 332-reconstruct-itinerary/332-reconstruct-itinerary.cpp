class Solution {
    map<string,priority_queue<string,vector<string>,greater<>>> mp;
    vector<string> ans;
    void dfs(string s){
        while(!mp[s].empty()){
            string x=mp[s].top();
            mp[s].pop();
            dfs(x);
        }
        ans.push_back(s);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
      for(auto i: tickets){
          mp[i[0]].push(i[1]);
      }
    dfs("JFK");
      reverse(ans.begin(),ans.end());
      return ans;
      
        
    }
};