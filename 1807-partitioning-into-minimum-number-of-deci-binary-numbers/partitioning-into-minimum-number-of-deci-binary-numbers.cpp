class Solution {
public:
    int minPartitions(string n) {
        int maxDi = 0;
        
        for(char ch : n) {
            maxDi = max(maxDi, ch - '0');
        }
        
        return maxDi;
    }
};