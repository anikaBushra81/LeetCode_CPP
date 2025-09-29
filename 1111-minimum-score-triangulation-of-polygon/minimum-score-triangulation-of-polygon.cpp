class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> v(n,vector<int>(n,0));
        for(int l=2;l<n;l++)
        {
            for(int i=0;i+l<n;i++)
            {
                int j=i+l;
                v[i][j]=INT_MAX;
                for(int k=i+1;k<j;k++)
                {
                    v[i][j]=min(v[i][j],v[i][k] + v[k][j] + values[i]*values[k]*values[j]);
                }
            }
        }
        return v[0][n-1];
    }
};