class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        map<char,int> mp;
        for(auto it: s){
            mp[it]++;
        }
        for(auto it: mp){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
            pair<int,char> x=pq.top();
            int ct=x.first;
            char c=x.second;
            pq.pop();
            while(ct--){
                ans+=c;
            }
        }
        return ans;
        
    }
};