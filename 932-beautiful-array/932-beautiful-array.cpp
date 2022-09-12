class Solution {
public:
    void divide(vector<int>& S, int l, int r) {
        if (r - l <= 1) return;
        vector<int> odd, even;
        for (int i = l; i <= r; ++i) {
            if ((i + 1 - l) & 1) { //using relative index
                odd.push_back(S[i]);
            } else {
                even.push_back(S[i]);
            }
        }
        std::copy(odd.begin(), odd.end(), S.begin() + l);
        std::copy(even.begin(), even.end(), S.begin() + l + odd.size());
        int m = (r - l) / 2 + l;
        divide(S, l, m);
        divide(S, m + 1, r);
    }
    
    vector<int> beautifulArray(int N) {
        vector<int> S;
        for (int i = 1; i <= N; ++i) {
            S.push_back(i);
        }
        divide(S, 0, N - 1);
        return S;
    }
    
    
};