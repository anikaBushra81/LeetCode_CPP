class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0;

        sort(nums.begin(), nums.end());

        int result = INT_MAX;
        for (int i = 0; i + k - 1 < nums.size(); i++) {
            result = min(result, nums[i + k - 1] - nums[i]);
        }

        return result;
    }
};
