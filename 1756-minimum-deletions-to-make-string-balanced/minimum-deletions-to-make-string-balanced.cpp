class Solution {
public:
    int minimumDeletions(string s) {
        int d = 0;      
        int bCount = 0; 

        for (char c : s) {
            if (c == 'b') {
                bCount++;
            } else { 
                d = min(d + 1, bCount);
            }
        }
        return d;
    }
};