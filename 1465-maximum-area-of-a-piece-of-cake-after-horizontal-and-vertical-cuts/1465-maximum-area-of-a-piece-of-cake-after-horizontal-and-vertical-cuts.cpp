class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        int mod =1e9+7;
        sort(vc.begin(),vc.end());
        sort(hc.begin(),hc.end());
        
        int mx_h=hc[0];
        int mx_w=vc[0];
        
        for(int i=0; i<hc.size()-1; i++){
            int diff= hc[i+1]-hc[i];
            mx_h=max(mx_h, diff);
        }
        mx_h=max(mx_h, h-hc[hc.size()-1]);
        for(int i=0; i<vc.size()-1; i++){
            int diff= vc[i+1]-vc[i];
            mx_w=max(mx_w, diff);
        }
        mx_w=max(mx_w, w-vc[vc.size()-1]);
   
        return (mx_h*1LL*mx_w)%mod;
    }
};