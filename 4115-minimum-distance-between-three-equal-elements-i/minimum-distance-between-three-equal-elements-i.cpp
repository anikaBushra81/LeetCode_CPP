class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        
        // Step 1: store indices for each value
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        
        // Step 2: check each value group
        for (auto &p : mp) {
            vector<int> &v = p.second;
            
            // Need at least 3 occurrences
            if (v.size() < 3) continue;
            
            // Step 3: check consecutive triples
            for (int i = 0; i + 2 < v.size(); i++) {
                int dist = 2 * (v[i + 2] - v[i]);
                ans = min(ans, dist);
            }
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};