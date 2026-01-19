class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int a=mat.size();
        int b=mat[0].size();

        vector<vector<int>>pre(a+1,vector<int>(b+1,0));
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=b;j++)
            {
                pre[i][j]=mat[i-1][j-1]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
            }
        }

        auto c=[&](int k)
        {
            for(int i=0;i+k<=a;i++)
            {
                for(int j=0;j+k<=b;j++)
                {
                    int sum=pre[i+k][j+k]-pre[i][j+k]-pre[i+k][j]+pre[i][j];
                    if(sum<=threshold)
                    {
                        return true;
                    }
                }
            }
            return false;
        };

        int l=0,h=min(a,b),result=0;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(c(mid))
            {
                result=mid;
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return result;
        
    }
};