class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int ans=0,n=apples.size();
        priority_queue<pair<int,int>,vector <pair<int,int>> , greater <pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            if(apples[i]>0){
                pq.push({i+days[i]-1,apples[i]});
            }
            while(!pq.empty() and pq.top().first<i) pq.pop();
            if(pq.empty()) continue;
            ans++;
            auto p=pq.top();
            p.second-=1;
            pq.pop();
            if(p.second) pq.push(p);
        }
        int j=n;
        while(!pq.empty()){
            while(!pq.empty() and pq.top().first<j) pq.pop();
            if(pq.empty()) break;
            int x=min(pq.top().first-j+1,pq.top().second);
            ans+=x;
            j+=x;
            pq.pop();
            
        }
        return ans;
        
    }
};