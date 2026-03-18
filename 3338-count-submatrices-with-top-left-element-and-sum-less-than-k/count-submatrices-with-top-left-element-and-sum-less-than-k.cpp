class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int a = grid.size();
        int b = grid[0].size();
        
        int cunt = 0;
        
        for(int i = 0; i < a; i++) {
            for(int j = 0; j < b; j++) {
                
                if(i > 0) grid[i][j] += grid[i-1][j];
                if(j > 0) grid[i][j] += grid[i][j-1];
                if(i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];
                
                if(grid[i][j] <= k) cunt++;
            }
        }
        
        return cunt;
    }
};