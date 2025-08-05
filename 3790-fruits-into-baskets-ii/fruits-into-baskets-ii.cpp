class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<int>use(n,0);
        int flag=0;
        for(int i=0;i<n;i++)
        {
            bool place=false;
            for(int j=0;j<n;j++)
            {
                if(use[j]==0 && baskets[j]>=fruits[i])
                {
                    use[j]=1;
                    place=true;
                    break;
                }
            }
            if(!place)
            {
                flag++;
            }
        }
        return flag;
    }
};