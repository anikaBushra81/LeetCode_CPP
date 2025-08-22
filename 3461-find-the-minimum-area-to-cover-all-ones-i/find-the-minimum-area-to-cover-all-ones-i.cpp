class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int a=grid.size();
        int b=grid[0].size();
        int minRow=a,minCol=b,maxRow=-1,maxCol=-1;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                if(grid[i][j]==1)
                {
                    minRow=min(minRow,i);
                    maxRow=max(minRow,i);
                    minCol=min(minCol,j);
                    maxCol=max(maxCol,j);
                }
            }
        }

        int h=maxRow-minRow+1;
        int w=maxCol-minCol+1;

        return h*w;

        
    }
};