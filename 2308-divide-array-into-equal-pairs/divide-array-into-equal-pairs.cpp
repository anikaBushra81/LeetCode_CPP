class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> freq(501, 0);

        for (int x : nums) {
            freq[x]++;
        }

        for (int i = 1; i <= 500; i++) {
            if (freq[i] % 2 != 0) {
                return false;
            }
        }

        return true;
    }
};