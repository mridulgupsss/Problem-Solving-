class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>> >mp;
    TimeMap() {
       
    }
    
    void set(string key, string value, int timestamp) {
       mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = upper_bound(mp[key].begin(), mp[key].end(), pair<int, string>(timestamp, ""), [](
    const pair<int, string>& a, const pair<int, string>& b) { return a.first < b.first; });
        if(it==mp[key].begin())return "";
        it--;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */