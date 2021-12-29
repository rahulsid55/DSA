class node
{
    public:
    node *links[26];
    bool isEnd;
    node(){
        isEnd=false;
        for(int i=0;i<26;i++)
        {
          links[i]=NULL;
        }
    }
};
class Trie {
public:
    node *root=new node();
    Trie() {

    }
    
    void insert(string word) {
        int n=word.length();
        node *temp=root;
        for(int i=0;i<n;i++){
            if(!temp->links[word[i]-'a'])
            {
                temp->links[word[i]-'a']=new node();
            }
            temp=temp->links[word[i]-'a'];
        }
        temp->isEnd=true;
    }
    
    bool search(string word) {
        node *temp=root;
        for(int i=0;i<word.length();i++){
            if(temp->links[word[i]-'a']==NULL)
                return false;
            temp=temp->links[word[i]-'a'];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string word) {
        node *temp=root;
        for(int i=0;i<word.length();i++){
            if(temp->links[word[i]-'a']==NULL)
                return false;
            temp=temp->links[word[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */