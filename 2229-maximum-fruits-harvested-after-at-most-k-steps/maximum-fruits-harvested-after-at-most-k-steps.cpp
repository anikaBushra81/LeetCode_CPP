class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=fruits.size();
        int l=0;
        int totalFruits=0,maxFruit=0;
        for(int r=0;r<n;r++)
        {
            totalFruits+=fruits[r][1];
            while(l<=r && vis(fruits[l][0],fruits[r][0],startPos)>k)
            {
                totalFruits-=fruits[l][1];
                l++;
            }
            maxFruit=max(maxFruit,totalFruits);
        }
        return maxFruit;
        
    }

    int vis(int L,int R,int startPos)
    {
        if(R<= startPos)
        {
            return startPos-L;
        }
        if(L>=startPos)
        {
            return R-startPos;
        }

        return min(2*(startPos-L)+(R-startPos), 2*(R-startPos)+(startPos-L));
    }
};