class Solution {
public:  // most optimal aproach SC : O(N) 
    int maximumSwap(int num) {
       string str = to_string(num);
      unordered_map<int, int> mp;
        for(int i=0; i<str.size(); i++){
            mp[str[i]-'0']=i;
        }
        
        int curr=0; int i=9;
        while(i>=0){
            if(mp.find(i)!=mp.end()){
                int idx= mp[i];
                if(idx>curr){
                    if(str[curr]==str[idx]){
                        curr++; continue;
                    }
                    swap(str[curr], str[idx]); break;
                }
                else{
                    curr++;
                }
            }
            i--;
        }
    
        
        return stoi(str);
    }
};