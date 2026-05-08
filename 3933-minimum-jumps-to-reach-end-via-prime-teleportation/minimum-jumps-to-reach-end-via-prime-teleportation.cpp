class Solution {
public:
    vector<int> spf;

    void sieve(int n) {
        spf.resize(n + 1);
        for (int i = 0; i <= n; i++) spf[i] = i;

        for (int i = 2; i * i <= n; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= n; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }
    }

    vector<int> getPrimeFactors(int x) {
        vector<int> primes;
        while (x > 1) {
            int p = spf[x];
            primes.push_back(p);
            while (x % p == 0) x /= p;
        }
        return primes;
    }

    bool isPrimeNumber(int x) {
        if (x < 2) return false;
        return spf[x] == x;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int maxA = *max_element(nums.begin(), nums.end());

        sieve(maxA);

        unordered_map<int, vector<int>> primeToIndices;

        // Build prime -> indices mapping
        for (int i = 0; i < n; i++) {
            vector<int> primes = getPrimeFactors(nums[i]);
            for (int p : primes) {
                primeToIndices[p].push_back(i);
            }
        }

        vector<int> dist(n, -1);
        queue<int> q;

        q.push(0);
        dist[0] = 0;

        vector<int> dirs = {-1, 1};

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            int d = dist[i];
            if (i == n - 1) return d;

            // adjacent moves
            for (int dir : dirs) {
                int ni = i + dir;
                if (ni >= 0 && ni < n && dist[ni] == -1) {
                    dist[ni] = d + 1;
                    q.push(ni);
                }
            }

            // prime teleport
            int val = nums[i];
            if (isPrimeNumber(val)) {
                int p = val;

                if (primeToIndices.count(p)) {
                    for (int j : primeToIndices[p]) {
                        if (dist[j] == -1) {
                            dist[j] = d + 1;
                            q.push(j);
                        }
                    }
                    // important: clear to avoid reprocessing
                    primeToIndices[p].clear();
                }
            }
        }

        return -1;
    }
};