class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        if (n == 1) return 0;

        // Store indices for each value
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int i = q.front();
                q.pop();

                // Reached last index
                if (i == n - 1)
                    return steps;

                // Same value jumps
                for (int next : mp[arr[i]]) {
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }

                // Clear to avoid reprocessing
                mp[arr[i]].clear();

                // i + 1
                if (i + 1 < n && !visited[i + 1]) {
                    visited[i + 1] = true;
                    q.push(i + 1);
                }

                // i - 1
                if (i - 1 >= 0 && !visited[i - 1]) {
                    visited[i - 1] = true;
                    q.push(i - 1);
                }
            }

            steps++;
        }

        return -1;
    }
};