class Solution {
public:
    int possibleStringCount(string word) {
        vector<pair<char,int>>p;
        int n=word.size();
        int i=0;
        while(i<n)
        {
            char curr=word[i];
            int count=0;
            while(i<n && word[i]==curr)
            {
                count++;
                i++;
            }
            p.push_back({curr,count});
        }
        int total=1;
        for(auto &[c,count]:p)
        {
            for(int j=1;j<count;j++)
            {
                total++;
            }
        }
        return total;
        
    }
};