class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        
        int n=prices.size();
        long long origi=0;
        for(int i=0;i<n;i++)
        {
            origi+=1LL*strategy[i]*prices[i];
        }

        vector<long long>pref(n+1,0);
        for(int i=0;i<n;i++)
        {
            pref[i+1]=pref[i]+1LL*strategy[i]*prices[i];
        }

        vector<long long> pricePref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pricePref[i + 1] = pricePref[i] + prices[i];
        }

        long long ans=origi;

        int half = k / 2;
        for (int l = 0; l + k <= n; l++) {
            long long oldContribution = pref[l + k] - pref[l];
            
            long long newContribution =
                pricePref[l + k] - pricePref[l + half];
            
            long long curr = origi -  oldContribution + newContribution;
            ans = max(ans, curr);
        }

        return ans;
    }

    
};