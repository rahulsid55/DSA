class node{
    public:
    node *links[26];
    bool end;
    node(){
        for(int i=0;i<26;i++)
            links[i]=NULL;
        end=false;
    }
};
string completeString(int n, vector<string> &a){
    node *root=new node();
    node *temp=root;
    for(auto s: a){
        //cout<<s;
        temp=root;
        for(int i=0;i<s.length();i++)
        {
           int index=s[i]-'a';
            if(temp->links[index]==NULL)
                temp->links[index]=new node();
            temp=temp->links[index];
         }
         temp->end=true;
        
    }
    string ans="";
    int max_len=0;
    for(string s:a){
        int len=0,flag=0;
        temp=root;
        for(int i=0;i<s.length();i++){
             int index=s[i]-'a';
            temp=temp->links[index];
            if(temp->end==false)
            {
                flag=1;
                break;
            }
            else
            {
                len++;
                
            }
        }
        if(flag==0)
        {
            if(len>max_len)
            {
                max_len=len;
                ans=s;
            }
            else if(len==max_len)
            {
                if(s<ans)
                    ans=s;
            }
        }
    }
    
    return ans==""?"None":ans;
    }
