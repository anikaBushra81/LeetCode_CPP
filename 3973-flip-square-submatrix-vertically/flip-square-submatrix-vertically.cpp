class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        int t = x;
        int b = x + k - 1;
        
        while (t < b) {
            for (int col = y; col < y + k; col++) {
                swap(grid[t][col], grid[b][col]);
            }
            t++;
            b--;
        }
        
        return grid;
    }
};