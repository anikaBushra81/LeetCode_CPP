class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>s;
        int l=0,r=0;
        int currentSum=0,maxSum=0;
        while(r<nums.size())
        {
            while(s.count(nums[r]))
            {
                s.erase(nums[l]);
                currentSum-=nums[l];
                l++;
            }
            s.insert(nums[r]);
            currentSum+=nums[r];
            maxSum=max(maxSum,currentSum);
            r++;
        }
        return maxSum;
        
    }
};