class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int m = 1; m < s.size(); m++) {
            if(s[m] == '1' && s[m-1] == '0') {
                return false;
            }
        }
        return true;
    }
};