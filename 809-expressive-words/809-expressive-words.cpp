class Solution {
public:
    string convert(string t){
        int n=t.length();
        string temp="";
        int cnt=1,i=1;
        while(i<n){
            while(i<n and t[i]==t[i-1]){
                cnt++;
                i++;
            }
            if(i>=n){
                break;
            }
            temp+=(t[i-1]+to_string(cnt));
            i++;
            cnt=1;
        }
        temp+=(t[i-1]+to_string(cnt));
        return temp;
    }
    bool solve(string x,string y){
        x=convert(x);
        y=convert(y);
        int i=0,j=0;
        cout<<x<<" "<<y<<endl; 
        if(x.length()!=y.length()) return false;
        while(i<x.length() and j<y.length()){
            string x1=x.substr(i,2);
            string x2=y.substr(j,2);
            cout<<x1<<" "<<x2<<endl;
            if(x1[0]!=x2[0]) return false;
            if(x1[1]-x2[1]<0 or (x1[1]=='2' and x2[1]=='1')) return false;
            i+=2;
            j+=2;
        }
        return true;
    }
    int expressiveWords(string s, vector<string>& words) {
        int cnt=0;
        for(int i=0;i<words.size();i++){
            if(solve(s,words[i]))
                cnt++;
        }
        return cnt;
        
    }
};