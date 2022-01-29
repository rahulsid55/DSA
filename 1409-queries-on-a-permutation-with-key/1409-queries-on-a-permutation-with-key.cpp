class Solution {
public:
    vector<int> processQueries(vector<int>& q, int m) {
        vector<int> ans;
        int arr[m+1];
        for(int i=1;i<=m;i++) arr[i]=i-1;
        for(int i=0;i<q.size();i++){
            ans.push_back(arr[q[i]]);
            int x=arr[q[i]];
            
            for(int j=1;j<(m+1);j++){
                if(arr[j]<x){
                    arr[j]=(arr[j]+1);
                }
            }
            arr[q[i]]=0;
        }
        return ans;
    }
};