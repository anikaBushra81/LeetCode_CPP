class Solution {
public:
    int minCost(int n, vector<vector<int>>& edge) {
        vector<vector<pair<int,int>>> graph(n);

        for (auto &e : edge) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});       
            graph[v].push_back({u, 2 * w});
        }

        const long long INF = 1e18;
        vector<long long> dist(n, INF);
        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;

            for (auto &[v, w] : graph[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n-1] == INF ? -1 : dist[n-1];
    }
};
