class Solution {
    typedef array<int, 2> ii;
    bool dp[1 << 12][12];
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        const int n = graph.size();
        for (int i = 0; i < (1 << n); i++)
            for (int j = 0; j < n; j++) dp[i][j] = 0;
        queue<ii> q;
        for (int i = 0; i < n; i++) {
            dp[1 << i][i] = 1;
            q.push({i, 1 << i});
        }
        int dist = 0, target = (1 << n) - 1;
        while (q.size()) {
            int s = q.size();
            while (s--) {
                ii u = q.front();
                q.pop();
                for (int v : graph[u[0]]) {
                    int mask = u[1] | (1 << v);
                    if (mask == target) return 1 + dist;
                    if (!dp[mask][v]) {
                        dp[mask][v] = 1;
                        q.push({v, mask});
                    }
                }
            }
            dist++;
        }
        return 0;
    }
};