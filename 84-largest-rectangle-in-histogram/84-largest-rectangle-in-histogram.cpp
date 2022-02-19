class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        // next smaller ele to left and right 
        stack<int> st1, st2;
        int n = arr.size();
         st2.push(n-1);
        vector<int> v (n);
        v[n-1]=n;
        for(int i=n-2; i>=0; i--){
            while(!st2.empty() && arr[st2.top()]>=arr[i]){
                st2.pop();
            }
            if(st2.empty()) v[i]=n;
            else v[i]=st2.top();
            st2.push(i);
        }
        
        int ans =arr[0];
        for(int i=0; i<n; i++){

            while(!st1.empty() && arr[st1.top()]>=arr[i]){
                st1.pop();
            }
            int left;
            if(st1.empty()) left=-1;
            else left= st1.top();
            st1.push(i);
         
            int area = arr[i]*1LL*(v[i]-left-1);
            ans = max(ans, area);

        }
        
        return ans;
    }
};