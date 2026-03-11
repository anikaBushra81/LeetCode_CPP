class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;       
        int m = 0;
        int tmp = n;      
        while(tmp > 0){
            m = (m << 1) | 1;
            tmp >>= 1;
        }   
        return n ^ m;
    }
};