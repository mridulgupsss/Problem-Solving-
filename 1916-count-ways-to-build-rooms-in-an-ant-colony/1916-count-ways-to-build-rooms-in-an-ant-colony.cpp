class Solution {
public:
#define mod 1000000007

vector<vector<long long> > tr;
vector<long long> sz;
int n;
vector<long long> fact, ans;

void pre(int n){
    fact.resize(n, 1);
    ans.resize(n, 1);
    for(int i = 2;i<n;i++){
        fact[i] = (fact[i-1] * i)%mod;
    }
}

long long powmod(long long base,long long exponent){
    if(exponent<0) exponent+=mod-1;
    long long ans=1;
    while(exponent){
        if(exponent&1)ans=(ans*base)%mod;
        base=(base*base)%mod;
        exponent/=2;
    }
    return ans;
}

void dfs(int root){
    sz[root] = 1;
    long long prod1 = 1, prod2 = 1;
    for(auto ch: tr[root]){
        dfs(ch);
        sz[root] += sz[ch];
        ans[root] = (ans[root] * ans[ch])%mod;
        prod1 = (prod1 * fact[sz[ch]])%mod;
    }
    
    prod2 = fact[sz[root] - 1];
    ans[root] = (ans[root] * prod2)%mod;
    ans[root] = (ans[root] * powmod(prod1, mod-2))%mod;
}

int waysToBuildRooms(vector<int>& pr) {
    int n = pr.size();
    tr.resize(n);
    ans.resize(n, 1);
    sz.resize(n, 0);

    // build tree
    for(int i = 1;i < n;i++){
        int par = pr[i];
        tr[par].push_back(i);
    }
    
    // pre compute factorials
    pre(n);
    
    // iterate over the tree
    dfs(0);
    return ans[0];
}
};