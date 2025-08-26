class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea=-1,maxDiagonal=-1;
        for(auto &r :dimensions )
        {
            int length=r[0],width=r[1];
            int diagonal=length*length + width*width;
            int area=length*width;

            if(diagonal>maxDiagonal)
            {
                maxDiagonal=diagonal;
                maxArea=area;
            }
            else if(diagonal== maxDiagonal)
            {
                maxArea=max(maxArea,area);
            }
        }
        return maxArea;
        
    }
};