class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>result;
        for(int i=0;i<s.length();i+=k)
        {
            string tmp=s.substr(i,k);
            while(tmp.length()<k)
            {
                tmp+=fill;
            }
            result.push_back(tmp);
        }
        return result;
        
    }
};