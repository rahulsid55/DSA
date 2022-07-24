class Solution {
public:
    void solve(vector<string> &ds,vector<string> &ans,string s,int i){
        if(i==s.length() and ds.size()==4){
                cout<<"Hit"<<endl;
                ans.push_back(ds[0]+'.'+ds[1]+'.'+ds[2]+'.'+ds[3]);
            return;
        }
            string x="";
            for(int k=i;k<s.length() && ds.size()<4;k++){
                if(s[k]-'0'>9) continue;
                x+=s[k];
                int y=stoi(x); 
                if(y>=0 and y<=255){
                    cout<<x<<" ";
                    ds.push_back(x);
                    solve(ds,ans,s,k+1);
                    ds.pop_back();
                }
                if(y<=0 or y>255) {
                    break;
                }
            }
        }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ds;
        vector<string> ans;
        solve(ds,ans,s,0);
        return ans;
        
    }
};