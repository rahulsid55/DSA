class Solution {
public:
    int countKDifference(vector<int>& arr,int k) {
        map<int,int> mp;
        int ct=0,n=arr.size();
        for(int i=0;i<n;i++){
            if(mp.count(arr[i]-k)){
                ct+=mp[arr[i]-k];
            }
            if(mp.count(arr[i]+k)){
                ct+=mp[arr[i]+k];
            }
            mp[arr[i]]++;
        }
        return ct;
        
        
    }
};