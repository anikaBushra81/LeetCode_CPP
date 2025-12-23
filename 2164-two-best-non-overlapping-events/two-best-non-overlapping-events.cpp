#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) 
    {
        sort(events.begin(), events.end(), [](auto &a, auto &b){
            return a[1] < b[1]; 
        });

        int n = events.size();
        vector<int> endTimes(n), maxVal(n);
        
        for(int i = 0; i < n; i++) {
            endTimes[i] = events[i][1];
            maxVal[i] = events[i][2];
            if(i > 0) maxVal[i] = max(maxVal[i], maxVal[i-1]);
        }

        int ans = 0;
        for(auto &e : events)
        {
            int idx = upper_bound(endTimes.begin(), endTimes.end(), e[0]-1) - endTimes.begin() - 1;
            int sum = e[2];
            if(idx >= 0) sum += maxVal[idx];
            ans = max(ans, sum);
        }

        return ans;
    }
};
