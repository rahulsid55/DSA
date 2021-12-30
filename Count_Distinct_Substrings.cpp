class node{
    public:
    node *links[26];
    node()
    {
        for(int i=0;i<26;i++)
            links[i]=NULL;
    }
};

int countDistinctSubstrings(string &s)
{
    string l="";
    int count=0;
    node *root=new node();
    for(int i=0;i<s.length();i++)
    {
        node *temp=root;
        for(int j=i;j<s.length();j++)
        {
            int index=s[j]-'a';
            if(!temp->links[index])
            {
                count++;
                temp->links[index]=new node();
            }
            temp=temp->links[index];
        }
    }
    return count+1;
}
