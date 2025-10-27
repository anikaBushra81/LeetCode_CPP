class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>dev;
        for(auto &r:bank)
        {
            int count=0;
            for(char c:r)
            {
                if(c=='1')
                {
                    count++;
                }
            }
            if(count>0)
            {
                dev.push_back(count);
            }
        }
        int beam=0;
        for(int i=1;i<dev.size();i++)
        {
            beam+=dev[i-1]*dev[i];
        }
        return beam;
    }
};