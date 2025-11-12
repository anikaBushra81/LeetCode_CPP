class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int o=count(nums.begin(),nums.end(),1);
        if(o>0)
        {
            return n-o;
            
        }
        int min_length=n+1;
        for(int i=0;i<n;i++)
        {
            int k=nums[i];
            for(int j=i;j<n;j++)
            {
                k=gcd(k,nums[j]);
                if(k==1)
                {
                    min_length=min(min_length,j-i+1);
                    break;
                }
            }
        }
        if(min_length== n+1)
        {
            return -1;
        }
        return min_length+n-2;
    }
};