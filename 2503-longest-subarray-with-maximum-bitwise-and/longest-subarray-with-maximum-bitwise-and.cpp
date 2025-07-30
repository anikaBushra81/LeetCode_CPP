class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxValue=*max_element(nums.begin(),nums.end());
        int lng=0,curr=0;
        for(int num:nums)
        {
            if(num==maxValue)
            {
                curr++;
                lng=max(lng,curr);
            }
            else
            {
                curr=0;

            }
        }
        return lng;
        
    }
};