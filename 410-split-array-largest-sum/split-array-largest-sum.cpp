class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long low = 0, high = 0;

        for (int x : nums) {
            low = max(low, (long long)x);
            high += x;
        }

        while (low < high) {
            long long mid = low + (high - low) / 2;

            int subarrays = 1;
            long long currentSum = 0;

            for (int x : nums) {
                if (currentSum + x > mid) {
                    subarrays++;
                    currentSum = x;
                } else {
                    currentSum += x;
                }
            }

            if (subarrays <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return (int)low;
    }
};