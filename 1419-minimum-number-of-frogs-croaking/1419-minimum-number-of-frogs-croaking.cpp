class Solution {
public:// same approach as meeting room 2: 
    int minNumberOfFrogs(string croakOfFrogs) {
       string croak="croak";
        unordered_map<char, int> positions;
        for(int i=0; i<5; i++){
            positions[croak[i]]=i;
        }
        
       int frogs=0; 
        unordered_map<char, int> freq;
        for(auto ch: croakOfFrogs){
            freq[ch]++;
            if(ch=='c') continue;
            
            char prev_char=croak[positions[ch]-1];
            if(freq[prev_char]<freq[ch]) return -1;
            
            if(ch=='k'){
                frogs=max(frogs, freq['c']);
                for(auto &it: freq){
                    it.second--;
                }
                }
            }
        
        
        
        for(auto it: freq){
            if(it.second!=0) {
                return -1;
            }
        }
        
      return frogs;
    }
};