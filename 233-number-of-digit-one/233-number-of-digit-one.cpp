class Solution {
public:
    int countDigitOne(int num) {
        string s=to_string(num);
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') continue;
            else if(s[i]>'1'){
                int tot=(pow(10,n-i-1));
                int low=(s[i]-'0')*((n-i-1)*pow(10,n-i-2));
                ans+=tot+low;
            }
            else if(i==n-1){
                ans+=1;
            }
            else{
                int x=(stoi(s.substr(i+1)))+1;
                int y=((n-i-1)*pow(10,n-i-2));
                ans+=x+y;
            }
        }
        return ans;
        
        
    }
};