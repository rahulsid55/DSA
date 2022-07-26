class node{
    public:
    node *alpha[26];
    bool flag;
    node(){
        for(int i=0;i<26;i++) alpha[i]=NULL;
        flag=false;
    }
};
class WordDictionary {
public:
    node *root=new node();
    bool dfs(int i,string word,node *temp){
        if(i==word.length()){
            return temp->flag;
        }
        if(word[i]=='.'){
            for(int k=0;k<26;k++){
                if(temp->alpha[k]){
                    if(dfs(i+1,word,temp->alpha[k])) return true;;
                }
            }
        }
        else{
            //cout<<word[i]<<" "; 
            if(temp->alpha[word[i]-'a']){
                    if(dfs(i+1,word,temp->alpha[word[i]-'a'])) return true;;
            }
        }
        return false;
    }
    WordDictionary() {
        
    }
    
    void addWord(string word) {
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
        //cout<<word<<endl;
        return dfs(0,word,root);
        
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */