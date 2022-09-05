class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> st;
        for(auto a:arr){
            if(st.find(2*a)!=st.end() || (a%2==0 && st.find(a/2)!=st.end())){
                return true;
            }
            else st.insert(a);
        }
        
        return false;
    }
};