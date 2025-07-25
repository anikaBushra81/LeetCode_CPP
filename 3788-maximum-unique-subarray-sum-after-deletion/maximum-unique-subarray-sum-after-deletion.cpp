class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> s;
        for(int num:nums)
        {
            if(num>0)
            {
                s.emplace(num);
            }
        }
        if(s.empty())
        {
            return *max_element(nums.begin(),nums.end());
        }
        return accumulate(s.begin(),s.end(),0);
    }
};
