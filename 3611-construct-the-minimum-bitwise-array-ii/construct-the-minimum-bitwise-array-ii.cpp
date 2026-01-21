class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result;

        for (int y : nums) {
           
            if ((y & 1) == 0) {
                result.push_back(-1);
                continue;
            }

            
            int t = 0;
            int temp = y;
            while (temp & 1) {
                t++;
                temp >>= 1;
            }

            
            int x = y - (1 << (t - 1));
            result.push_back(x);
        }

        return result;
    }
};
