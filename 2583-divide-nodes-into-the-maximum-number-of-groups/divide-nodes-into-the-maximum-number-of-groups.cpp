class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> component(n + 1, -1);
        vector<vector<int>> components;

        for (int i = 1; i <= n; i++) {
            if (component[i] != -1)
                continue;

            vector<int> nodes;
            queue<int> q;

            q.push(i);
            component[i] = components.size();

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                nodes.push_back(u);

                for (int v : adj[u]) {
                    if (component[v] == -1) {
                        component[v] = component[i];
                        q.push(v);
                    }
                }
            }

            components.push_back(nodes);
        }

        vector<int> color(n + 1, -1);

        for (int i = 1; i <= n; i++) {
            if (color[i] != -1)
                continue;

            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else if (color[v] == color[u]) {
                        return -1;
                    }
                }
            }
        }

        // Find maximum number of groups for each component
        int answer = 0;

        for (auto &nodes : components) {
            int best = 0;

            for (int start : nodes) {
                vector<int> dist(n + 1, -1);
                queue<int> q;

                q.push(start);
                dist[start] = 1;

                int maxLevel = 1;

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (int v : adj[u]) {
                        if (dist[v] == -1) {
                            dist[v] = dist[u] + 1;
                            maxLevel = max(maxLevel, dist[v]);
                            q.push(v);
                        }
                    }
                }

                best = max(best, maxLevel);
            }

            answer += best;
        }

        return answer;
    }
};