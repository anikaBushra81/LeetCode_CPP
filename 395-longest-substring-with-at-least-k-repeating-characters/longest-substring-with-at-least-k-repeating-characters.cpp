class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size()==0 || k>s.size())
        {
            return 0;

        }
        unordered_map<char,int>f;
        for(char c:s)
        {
            f[c]++;
        }
        for(int i=0;i<s.size();i++)
        {
            if(f[s[i]]<k)
            {
                int l=longestSubstring(s.substr(0,i),k);
                int r=longestSubstring(s.substr(i+1),k);
                return max(l,r);
            }
        }
        return s.size();
        
    }
};