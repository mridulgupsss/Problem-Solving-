class Solution {
public:
    
    // https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/discuss/260882/C%2B%2B-O(S-log-N)-vs.-O(N-*-(S-%2B-log-N))
    
    bool queryString(string s, int n) {
        while (n>0){
            string str = bitset<32>(n--).to_string();
            if(s.find(str.substr(str.find("1")))==string::npos) return false;
        }
        return true;
    }
};