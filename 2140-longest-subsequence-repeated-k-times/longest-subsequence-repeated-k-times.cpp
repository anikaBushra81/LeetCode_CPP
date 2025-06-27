class Solution {
public:

    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int>f(26);
        for(char ch:s)
        {
            f[ch-'a']++;
        }
        vector<char>c;
        for(int i=25;i>=0;i--)
        {
            if(f[i]>=k)
            {
                c.push_back('a'+i);
            }
        }
        queue<string>q;
        for(char ch:c)
        {
            q.push(string(1,ch));
        }
        string ans="";
        while(!q.empty())
        {
            string cur=q.front();
            q.pop();
            if(cur.size()>ans.size())
            {
                ans=cur;
            }
            for(char ch:c)
            {
                string next=cur+ch;
                if(Subsequence(s,next,k))
                {
                    q.push(next);
                }
            }

        }
        return ans;
    }

        bool Subsequence(const string &s, const string &t,int k)
    {
        int position=0,match=0;
        int n=s.size();
        int m=t.size();
        for(char ch:s)
        {
            if(ch==t[position])
            {
                position++;
                if(position==m)
                {
                    position=0;
                    match++;
                    if(match==k)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
        
};