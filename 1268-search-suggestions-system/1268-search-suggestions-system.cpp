class Solution {
public:
vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n=products.size();
        sort(products.begin(),products.end());
        vector<vector<string>>ans;
        vector<string>temp;
        string curr="";
        for(auto c:searchWord){
            curr+=c;                // adding character, like -> m-->mo-->mou-->mous--->mouse
            temp.clear();         //reusing the same vector
            for(int i=0;i<n;i++){
                string s=products[i];
                if(s.substr(0,curr.length())==curr){              //finding the prefix containing words in the list
                    temp.push_back(s);
                }
                if(temp.size()==3)break;         //question asked for 3 words so we break at 3
            }
            ans.push_back(temp);
        }
        return ans;
    }
};