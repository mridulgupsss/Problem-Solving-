class SnapshotArray {
public:
    vector<unordered_map<int, int>> v;
    int snap_idd=0;
    SnapshotArray(int length) {
  
        for(int i=0; i<length; i++){
            unordered_map<int,int> mpp;
            v.push_back(mpp);
        }
    }
    
    void set(int index, int val) {
        v[index][snap_idd]=val;
    }
    
    int snap() {
        snap_idd++;
        return snap_idd-1;
    }
    
    int get(int index, int snap_id) {
          unordered_map<int, int> &mp = v[index];
        while(snap_id>=0 && mp.find(snap_id)==mp.end()){
            snap_id--;

        }
        if(snap_id>=0) return mp[snap_id];
        else return 0;
    }                        
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */