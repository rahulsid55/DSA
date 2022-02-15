class Solution {
public:
    int countConsistentStrings(string s, vector<string>& words) {
        int a[26];
        memset(a,0,sizeof(a));
        for(int i=0;i<s.length();i++){
            a[s[i]-'a']=1;
        }
        int c=0;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].length();j++){
                if(a[words[i][j]-'a']!=1){
                    //cout<<words[i]<<endl;
                    c++;
                    break;
                }
            }
        }
        return words.size()-c;
    }
};