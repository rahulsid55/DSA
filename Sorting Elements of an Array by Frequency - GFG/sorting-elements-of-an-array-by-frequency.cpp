#include <bits/stdc++.h>
using namespace std;

bool static mysort(pair<int,int> a,pair<int,int> b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second>b.second;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,int> mp;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            mp[x]++;
        }
        for(auto x: mp){
            v.push_back({x.first,x.second});
        }
        sort(v.begin(),v.end(),mysort);
        for(auto x : v){
            for(int i=0;i<x.second;i++){
                cout<<x.first<<" ";
            }
        }
        cout<<endl;
    }
	return 0;
}