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
    
    void insert(string word) {
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
    
    bool search(string word) {
        Node *node =root;
        for(int i=0; i<word.size(); i++){
            int idx = word[i]-'a';
            
            if(node->linked[idx]==NULL){
                return false;
            }
            else{
                node = node->linked[idx];
            }
        }
        if( node->end==true){
            return true;
            
        }
         return false;
    }
    
    bool startsWith(string word) {
        Node *node =root;
        for(int i=0; i<word.size(); i++){
            int idx = word[i]-'a';
            
            if(node->linked[idx]==NULL){
                return false;
            }
            else{
                node = node->linked[idx];
            }
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