class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>>indexNum;
        for(int i=0;i<n;i++)
        {
            indexNum.push_back({nums[i],i});
        }

        sort(indexNum.begin(),indexNum.end(),[](pair<int,int> &a, pair<int,int> &b)
        {
            return a.first>b.first;
        });

        vector<pair<int,int>> topK(indexNum.begin(),indexNum.begin()+k);

        sort(topK.begin(),topK.end(),[](pair<int ,int> &a,pair<int ,int> &b)
        {
            return a.second<b.second;
        });

        vector<int>ans;
        for(auto &p : topK)
        {
            ans.push_back(p.first);
        }
        return ans;
        
    }
};