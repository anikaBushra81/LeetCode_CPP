class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long result=0,l=0;
        for(int i=0;i<prices.size();i++)
        {
            if(i>0 && prices[i-1]-prices[i]==1)
            {
                l++;
            }
            else
            {
                l=1;
            }
            result+=l;
        }
        return result;
    }
};