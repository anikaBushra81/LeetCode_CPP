class Solution {
public:
    struct BIT {
        int n;
        vector<long long> bit;

        BIT(int n) : n(n), bit(n + 1, 0) {}

        void update(int idx, long long val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        long long query(int idx) {
            long long sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        vector<int> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        BIT bit(vals.size());
        long long ans = 0;

        for (int p : pref) {
            int idx = lower_bound(vals.begin(), vals.end(), p) - vals.begin() + 1;

            ans += bit.query(idx - 1);

            bit.update(idx, 1);
        }

        return ans;
    }
};