class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        // dp[i] = number of distinct subsequences including empty
        vector<long long> dp(s.size() + 1, 0);

        dp[0] = 1;  // empty subsequence

        // last[c] = dp value before the previous occurrence of c
        vector<long long> last(26, 0);

        for (int i = 1; i <= s.size(); i++) {
            int c = s[i - 1] - 'a';

            long long newDp = (2 * dp[i - 1]) % MOD;

            // Remove duplicates caused by previous occurrence
            newDp = (newDp - last[c] + MOD) % MOD;

            dp[i] = newDp;

            // Save dp value before current character
            last[c] = dp[i - 1];
        }

        // Remove empty subsequence
        return (dp[s.size()] - 1 + MOD) % MOD;
    }
};