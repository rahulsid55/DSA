class Solution {
public:
    void next_permutation(string &s){
        int n=s.length();
        int i=n-2,x=-1;
        while(i>=0){
            if(s[i]<s[i+1]){
                x=i;
                break;
            }
            else{
                i--;
            }
        }
        if(x==-1){
            reverse(s.begin(),s.end());
            return ;
        }
        int y=n-1;
        while(y>=x){
            if(s[y]>s[x]){
                swap(s[y],s[x]);
                break;
            }
            else{
                y--;
            }
        }
        reverse(s.begin()+x+1,s.end());
        return ;
    }
    int getMinSwaps(string num, int k) {
        string s=num;
        while(k--)
            next_permutation(num);
        cout<<num;
        int ct=0;
        for(int i=0;i<num.length();i++){
            int j;
            if(num[i]!=s[i]){
                int j=i+1,l;
                for(j=i+1;i<num.length();j++){
                    if(num[j]==s[i]){
                        break;
                    }
                }
                for(int l=j;l>i;l--){
                    swap(num[l],num[l-1]);
                    ct++;
                }
                
            }
            
        }
        return ct;
        
    }
};