class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        long long total = 0;
        
        // Step 1: Calculate total sum
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }
        
        // If total is odd → impossible
        if (total % 2 != 0) return false;
        
        long long target = total / 2;
        
        // Step 2: Try horizontal cuts
        long long sum = 0;
        for (int i = 0; i < m - 1; i++) { // ensure both parts non-empty
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
            }
            if (sum == target) return true;
        }
        
        // Step 3: Compute column sums
        vector<long long> colSum(n, 0);
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                colSum[j] += grid[i][j];
            }
        }
        
        // Step 4: Try vertical cuts
        sum = 0;
        for (int j = 0; j < n - 1; j++) { // ensure both parts non-empty
            sum += colSum[j];
            if (sum == target) return true;
        }
        
        return false;
    }
};