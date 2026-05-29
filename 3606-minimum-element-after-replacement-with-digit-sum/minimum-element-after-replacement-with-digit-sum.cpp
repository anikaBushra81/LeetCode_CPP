class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
        int mn = INT_MAX;

        for (int x : nums) {
            int val = digitSum(x);
            mn = min(mn, val);
        }

        return mn;
    }
};