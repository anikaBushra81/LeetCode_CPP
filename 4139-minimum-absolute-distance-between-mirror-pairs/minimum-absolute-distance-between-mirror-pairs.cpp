class Solution {
public:
    int reverseNum(int x) {
        int r = 0;
        while (x > 0) {
            r = r * 10 + (x % 10);
            x /= 10;
        }
        return r;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp; 
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {

            if (mp.find(nums[i]) != mp.end()) {
                ans = min(ans, i - mp[nums[i]]);
            }

            int r = reverseNum(nums[i]);
            mp[r] = i;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};