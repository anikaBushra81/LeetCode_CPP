class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int total=0;
        if(x>y)
        {
            total+=removePattern(s,'a','b',x);
            total+=removePattern(s,'b','a',y);
        }
        else
        {
            total+=removePattern(s,'b','a',y);
            total+=removePattern(s,'a','b',x);
        }
        return total;
        
    }
    int removePattern(string &s,char first,char second,int p)
    {
        stack<char>stk;
        int sum=0;
        string tmp="";
        for(char ch:s)
        {
            if(!stk.empty()&&stk.top()==first&&ch==second)
            {
                stk.pop();
                sum+=p;
            }
            else
            {
                stk.push(ch);
            }
        }
        s="";
        while(!stk.empty())
        {
            s+=stk.top();
            stk.pop();
        }
        reverse(s.begin(),s.end());
        return sum;
    }
};