class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int>f;

        for(int val:basket1)
        {
            f[val]++;
        }

        for(int val:basket2)
        {
            f[val]--;
        }

        vector<int>n;
        int element=INT_MAX;

        for(int val: basket1)
        {
            element=min(element,val);
        }

        for(int val:basket2)
        {
            element=min(element,val);
        }

        for(auto&[val,count]:f)
        {
            if(count%2 !=0)
            {
                return -1;
            }

            // if(count>0)
            // {
                int times=abs(count)/2;
                for(int i=0;i<times;i++)
                {
                    n.push_back(val);
                }
            // }
            // element=min(element,val);
        }
        sort(n.begin(),n.end());

        long long m=0;
        int x=n.size();
        for(int i=0;i<x/2;i++)
        {
            m+=min(n[i],2*element);
        }
        return m;
        
    }
};