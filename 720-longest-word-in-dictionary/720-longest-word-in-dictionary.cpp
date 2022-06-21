class Solution {
    class Trie {
class Node{
    public:
        Node *linked[26];
        bool end;
    };
    private:
    Node *root;
    
    public:
    Trie() {
        root = new Node(); 
    }
    
    void insert(string &word) {
        Node *node =root;
        for(int i=0; i<word.size(); i++){
            int idx = word[i]-'a';
            
            if(node->linked[idx]==NULL){
                node->linked[idx]=new Node();
                node = node->linked[idx];
                
            }
            else{
                node = node->linked[idx];
            }
        }
        
        node->end=true;
        
        
        
    }
        
        bool check_if_all_prefix_exist(string &str){
            Node *node =root;
            for(int i=0; i<str.size(); i++){
                int idx= str[i]-'a';
                if(node->linked[idx]->end==false) return false;
                else{
                    node = node->linked[idx];
                }
            }
            
            return true;
        }

};
    
    
    
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for(auto str : words){
            trie.insert(str);
        }
        
        string longest ="";
            for(auto str: words){
            
                if(trie.check_if_all_prefix_exist(str)==true){
                    if(str.size()>longest.size()){
                        longest=str;
                    }
                    else if(str.size()==longest.size() && str<longest){
                        longest =str;
                    }
                }
            }
        
        return longest;
    }
};