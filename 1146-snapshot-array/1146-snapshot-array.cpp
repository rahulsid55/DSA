class SnapshotArray {
public:
    vector<map<int,int>> v;
    int n;
    SnapshotArray(int length) {
        n=0;
        v.resize(length);
        for(int i=0;i<length;i++) v[i][0]=0;
    }
    
    void set(int index, int val) {
        v[index][n]=val;
    }
    
    int snap() {
        n++;
        return n-1;
        
    }
    
    int get(int index, int snap_id) {
        if(v[index].find(snap_id)!=v[index].end()){
            return v[index][snap_id];
        }
        else{
            int ans;
            for(auto it: v[index]){
                if(it.first<snap_id) ans=it.second;
                else{
                    break;
                }
            }
            return ans;
        }
        return 0;
        
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */