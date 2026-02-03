class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int i = 1;

        while (i < n && nums[i] > nums[i - 1]) {
            i++;
        }
        if (i == 1 || i == n) return false; 


        int decStart = i;
        while (i < n && nums[i] < nums[i - 1]) {
            i++;
        }
        if (i == decStart || i == n) return false; 


        while (i < n && nums[i] > nums[i - 1]) {
            i++;
        }


        return i == n;
    }
};
