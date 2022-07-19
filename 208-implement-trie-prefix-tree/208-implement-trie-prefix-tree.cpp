class node{
  public:
    node *alpha[26];
    bool flag;
    node(){
        for(int i=0;i<26;i++){
            alpha[i]=NULL;
            flag=false;
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
            if(temp->alpha[word[i]-'a']==NULL){
                temp->alpha[word[i]-'a']=new node();
            }
            temp=temp->alpha[word[i]-'a'];
        }
        temp->flag=true;
        
    }
    
    bool search(string word) {
        int n=word.length();
        node *temp=root;
        for(int i=0;i<n;i++){
            if(temp->alpha[word[i]-'a']==NULL){
                return false;
            }
            temp=temp->alpha[word[i]-'a'];
        }
        return temp->flag;
        
    }
    
    bool startsWith(string word) {
        int n=word.length();
        node *temp=root;
        for(int i=0;i<n;i++){
            if(temp->alpha[word[i]-'a']==NULL){
                return false;
            }
            temp=temp->alpha[word[i]-'a'];
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