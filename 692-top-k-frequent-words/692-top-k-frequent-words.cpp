class Solution {
public:
    static bool comp(pair<int,string> &a,pair<int,string> &b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        sort(words.begin(),words.end());
        map<string,int> mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        vector<pair<int,string>> pq;
        for(auto it: mp){
            pq.push_back({it.second,it.first});
        }
        vector<string> v;
        sort(pq.begin(),pq.end(),comp);
        int i=0;
        while(i<k){
            v.push_back(pq[i].second);
            i++;
        }        
        
        return v;
    }
};