class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        set<int> s;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                s.insert(grid[i][j]); 
                
                for(int k=1;;k++){
                    
                    if(i-k<0 || i+k>=m || j-k<0 || j+k>=n) break;
                    
                    int sum = 0;
                    
                    int x=i-k,y=j;
                    
                    for(int t=0;t<k;t++) sum+=grid[x+t][y+t];
                    
                    x=i; y=j+k;
                    for(int t=0;t<k;t++) sum+=grid[x+t][y-t];
                    
                    x=i+k; y=j;
                    for(int t=0;t<k;t++) sum+=grid[x-t][y-t];
                    
                    x=i; y=j-k;
                    for(int t=0;t<k;t++) sum+=grid[x-t][y+t];
                    
                    s.insert(sum);
                }
            }
        }
        
        vector<int> res;
        
        for(auto it=s.rbegin(); it!=s.rend() && res.size()<3; it++){
            res.push_back(*it);
        }
        
        return res;
    }
};