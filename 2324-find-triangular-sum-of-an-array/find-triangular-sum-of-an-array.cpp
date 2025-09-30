class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        for(int l=n;l>1;l--)
        {
            for(int i=0;i<l-1;i++)
            {
                nums[i]=(nums[i]+nums[i+1])%10;
            }
        }
        return nums[0];
        
    }
};