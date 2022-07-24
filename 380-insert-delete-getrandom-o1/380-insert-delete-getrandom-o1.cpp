class RandomizedSet {
public:
    map<int,int> mp;
    vector<int> v;
    int sz;
    RandomizedSet() {
        sz=0;
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        mp[val]=sz;
        v.push_back(val);
        sz++;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end()){
            v[mp[val]]=v[sz-1];
            mp[v[sz-1]]=mp[val];
            v.pop_back();
            mp.erase(val);
            sz--;
            return true;;
        }
        return false;
        
    }
    
    int getRandom() {
        int ans=rand()%(sz);
        //cout<<sz<<" "<<ans;
        return v[ans];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */