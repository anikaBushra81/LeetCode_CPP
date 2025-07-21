class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        for(int i=0;i<s.length();i++)
        {
            int len=ans.length();
            if(len>=2 && ans[len-1]==s[i] && ans[len-2]==s[i])
            {
                continue;
            }
            ans+=s[i];
        }
        return ans;
        
    }
};