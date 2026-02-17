class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                
               
                int totalBits = __builtin_popcount(h) + __builtin_popcount(m);
                
                if (totalBits == turnedOn) {
                    string t = to_string(h) + ":";
                    
                   
                    if (m < 10)
                        t += "0";
                    
                    t += to_string(m);
                    
                    result.push_back(t);
                }
            }
        }
        
        return result;
    }
};