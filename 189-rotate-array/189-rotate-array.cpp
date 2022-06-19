class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n =arr.size();
        k=k%n;
        reverse(arr.begin(), arr.begin()+n-k);
        reverse(arr.begin()+n-k, arr.end());
        reverse(arr.begin(), arr.end());
    }
};