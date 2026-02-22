class Solution {
public:
    int binaryGap(int n) {
        int lastPos = -1;     
        int maxDistance = 0;  
        int pos = 0;          
        
        while (n > 0) {
            if (n & 1) {  
                if (lastPos != -1) {
                    maxDistance = max(maxDistance, pos - lastPos);
                }
                lastPos = pos;
            }
            n >>= 1;  
            pos++;
        }
        
        return maxDistance;
    }
};