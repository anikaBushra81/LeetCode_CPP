class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> freq;

        for (int x : nums) freq[x]++;

        int ans = 1;

        if (freq.count(1)) {
            ans = max(ans, freq[1] % 2 ? freq[1] : freq[1] - 1);
        }

        for (auto &[start, cnt] : freq) {
            if (start == 1) continue;

            long long cur = start;
            int pairs = 0;

            while (freq.count(cur)) {

                ans = max(ans, 2 * pairs + 1);

                long long nxt = cur * cur;

                if (freq[cur] < 2 || !freq.count(nxt))
                    break;

                pairs++;
                cur = nxt;
            }
        }

        return ans;
    }
};