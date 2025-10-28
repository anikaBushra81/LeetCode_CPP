class Solution {
public:

    bool simulate(vector<int> nums,int cur,int dir)
    {
        int n=nums.size();
        while(cur>=0 && cur<n)
        {
            if(nums[cur]==0)
            {
                cur+=dir;
            }
            else
            {
                nums[cur]--;
                dir=-dir;
                cur+=dir;
            }
        }
        for(int x:nums)
        {
            if(x!=0)
            {
                return false;
            }
        }
        return true;
    }
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                if(simulate(nums,i,1))
                {
                    count++;
                }
                if(simulate(nums,i,-1))
                {
                    count++;
                }
            }
        }
        return count;
    }
};