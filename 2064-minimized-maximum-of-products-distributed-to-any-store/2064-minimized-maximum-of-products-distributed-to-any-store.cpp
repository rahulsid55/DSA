#define ll long long
class Solution {
public:
    bool ispossible(int mid,vector<int> q,int n){
      ll s=0,t=0;
      for(int i=0;i<q.size();i++){
          t+=q[i]/mid;
          if(q[i]%mid>0)
             t++;
      }
        //cout<<t<<endl;
        if(t>n){
            return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& q) {
        ll l=1,h=0;
        for(auto it: q){
            h+=it;
        }
        while(l<=h){
            ll mid=l+(h-l)/2;
            cout<<mid<<" ";
            if(ispossible(mid,q,n)){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
        
    }
};