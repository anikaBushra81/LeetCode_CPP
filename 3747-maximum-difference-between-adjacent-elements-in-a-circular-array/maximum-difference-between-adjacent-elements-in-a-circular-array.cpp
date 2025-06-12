class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {

        int n=nums.size();
        int maxdif=0;
        
        for(int i=0;i<n;i++)
        {
            int dif=abs(nums[i]-nums[(i+1)%n]);
            maxdif=max(maxdif,dif);
        }
        return maxdif;
        
    }
};