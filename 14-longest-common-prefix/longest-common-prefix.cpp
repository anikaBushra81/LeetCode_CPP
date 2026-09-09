class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre=strs[0];
        for(int i=1;i<strs.size();i++)
        {
            int j=0;
            while(j<pre.size()&& j<strs[i].size()&& pre[j]==strs[i][j])
            {
                j++;
            }
            pre=pre.substr(0,j);
            if(pre=="")
            {
                return "";
            }
        }
        return pre;
       
    }
};