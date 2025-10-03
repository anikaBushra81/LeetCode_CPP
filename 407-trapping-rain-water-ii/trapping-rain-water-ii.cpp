class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int a=heightMap.size();
        int b=heightMap[0].size();
        if(a<=2 || b<=2)
        {
            return 0;
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<bool>>visited(a,vector<bool>(b,false));
        for(int i=0;i<a;i++)
        {
            pq.push({heightMap[i][0],i,0});
            pq.push({heightMap[i][b-1],i,b-1});
            visited[i][0]=visited[i][b-1]=true;
        }
        for(int j=1;j<b-1;j++)
        {
            pq.push({heightMap[0][j],0,j});
            pq.push({heightMap[a-1][j],a-1,j});
            visited[0][j]=visited[a-1][j]=true;
        }
        vector<int>d={1,0,-1,0,1};
        int rainWater=0;
        while(!pq.empty())
        {
            auto curr=pq.top();pq.pop();
            int height=curr[0];
            int x=curr[1],y=curr[2];
            for(int k=0;k<4;k++)
            {
                int bx=x+d[k];
                int by=y+d[k+1];
                if(bx<0 || by<0 || bx >=a || by>=b || visited[bx][by])
                {
                    continue;
                }
                visited[bx][by]=true;
                if(heightMap[bx][by]<height)
                {
                    rainWater=rainWater+height-heightMap[bx][by];

                }
                pq.push({max(height,heightMap[bx][by]),bx,by});
            }
        }
        return rainWater;
        
    }
};