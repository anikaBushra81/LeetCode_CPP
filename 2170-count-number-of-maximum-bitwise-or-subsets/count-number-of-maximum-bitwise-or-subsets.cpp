class Solution {
public:
    int maximumOr=0,count=0;
    void dfs(vector<int> &nums,int i,int currentOr)
    {
        if(i==nums.size())
        {
            if(currentOr==maximumOr)
            {
                count++;
                
            }
            return;
            
        }
        dfs(nums,i+1,currentOr | nums[i]);
        dfs(nums,i+1,currentOr);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        for(int num:nums)
        {
            maximumOr|=num;
        }
        dfs(nums,0,0);
        return count;
        
    }
};