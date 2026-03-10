class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int mod = 1e9 + 7;
        vector<vector<vector<int>>> mem(
            zero + 1, vector<vector<int>>(one + 1, vector<int>(2, -1)));

        function<int(int, int, int)> dp = [&](int zero, int one,
                                              int lastBit) -> int {
            if (zero == 0) {
                return (lastBit == 0 || one > limit) ? 0 : 1;
            } else if (one == 0) {
                return (lastBit == 1 || zero > limit) ? 0 : 1;
            }

            if (mem[zero][one][lastBit] == -1) {
                int res = 0;
                if (lastBit == 0) {
                    res = (dp(zero - 1, one, 0) + dp(zero - 1, one, 1)) % mod;
                    if (zero > limit) {
                        res = (res - dp(zero - limit - 1, one, 1) + mod) % mod;
                    }
                } else {
                    res = (dp(zero, one - 1, 0) + dp(zero, one - 1, 1)) % mod;
                    if (one > limit) {
                        res = (res - dp(zero, one - limit - 1, 0) + mod) % mod;
                    }
                }
                mem[zero][one][lastBit] = res % mod;
            }
            return mem[zero][one][lastBit];
        };

        return (dp(zero, one, 0) + dp(zero, one, 1)) % mod;
    }
};