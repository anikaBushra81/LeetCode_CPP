class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_set<int>s;
        int result=0;
        vector<int>v;
        for(int num:nums)
        {
            if(num==0)
            {
                result+=v.size();
                v.clear();
            }
            else
            {
                while(!v.empty() && v.back()>num)
                {
                    result++;
                    v.pop_back();
                }
                if(v.empty() || v.back()<num)
                {
                    v.push_back(num);
                }
                // s.insert(num);
            }
        }
        result+=v.size();
        return result;
    }
};