class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>v(m+1,vector<int>(n+1,0));
        for(string s : strs)
        {
            int z=count(s.begin(),s.end(),'0');
            int o=s.size()-z;
            for(int i=m;i>=z;i--)
            {
                for(int j=n;j>=o;j--)
                {
                    v[i][j]=max(v[i][j],v[i-z][j-o]+1);
                }
            }
        }
        return v[m][n];
        
    }
};