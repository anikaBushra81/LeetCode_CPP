class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int s0 = 0, s1 = 0;

        for(int i = 0; i < n; i++) {
            char exp0 = (i % 2 == 0) ? '0' : '1';
            char exp1 = (i % 2 == 0) ? '1' : '0';

            if(s[i] != exp0) s0++;
            if(s[i] != exp1) s1++;
        }

        return min(s0, s1);
    }
};