class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int a = n ^ (n >> 1);
        return (a & (a + 1)) == 0;
    }
};