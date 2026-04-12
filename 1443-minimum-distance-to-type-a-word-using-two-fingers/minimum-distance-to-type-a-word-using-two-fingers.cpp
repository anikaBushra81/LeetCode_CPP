class Solution {
public:
    int dist(int a, int b) {
        if (a == -1 || b == -1) return 0;
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    int minimumDistance(string word) {
        int n = word.size();
        
        vector<int> dp(26, 0);  // dp[c] = max saving if second finger at c
        int maxSave = 0;
        int total = 0;

        for (int i = 0; i < n - 1; i++) {
            int cur = word[i] - 'A';
            int next = word[i + 1] - 'A';

            int d = dist(cur, next);
            total += d;

            for (int c = 0; c < 26; c++) {
                dp[cur] = max(dp[cur], dp[c] + d - dist(c, next));
            }

            maxSave = max(maxSave, dp[cur]);
        }

        return total - maxSave;
    }
};