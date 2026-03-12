class DSU {
public:
    vector<int> parent, rankv;
    
    DSU(int n) {
        parent.resize(n);
        rankv.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    
    bool unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return false;
        
        if(rankv[a]<rankv[b]) swap(a,b);
        parent[b]=a;
        if(rankv[a]==rankv[b]) rankv[a]++;
        
        return true;
    }
};

class Solution {
public:
    
    bool can(int n, vector<vector<int>>& edges, int k, int x){
        
        DSU dsu(n);
        int used=0;
        
        vector<pair<int,int>> strong;
        vector<pair<int,int>> upgrade;
        
        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];
            
            if(must==1){
                if(s<x) return false;
                
                if(!dsu.unite(u,v)) return false;
                used++;
            }
            else{
                if(s>=x) strong.push_back({u,v});
                else if(2*s>=x) upgrade.push_back({u,v});
            }
        }
        
        for(auto &e:strong){
            if(dsu.unite(e.first,e.second)){
                used++;
                if(used==n-1) return true;
            }
        }
        
        int up=0;
        
        for(auto &e:upgrade){
            if(up==k) break;
            
            if(dsu.unite(e.first,e.second)){
                used++;
                up++;
                if(used==n-1) return true;
            }
        }
        
        return used==n-1;
    }
    
    
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        
        int l=1, r=200000, ans=-1;
        
        while(l<=r){
            int mid=(l+r)/2;
            
            if(can(n,edges,k,mid)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        
        return ans;
    }
};