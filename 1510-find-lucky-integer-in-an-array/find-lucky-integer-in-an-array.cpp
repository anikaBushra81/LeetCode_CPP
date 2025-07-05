class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>fre;
        for(int num: arr)
        {
            fre[num]++;
        }
        int result=-1;
        for(auto it:fre)
        {
            if(it.first==it.second)
            {
                result=max(result,it.first);
            }
        }
        return result;
    }
};