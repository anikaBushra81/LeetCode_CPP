class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int op = 0;

        while (true) {
            bool sorted = true;
            for (int i = 0; i + 1 < nums.size(); i++) {
                if (nums[i] > nums[i + 1]) {
                    sorted = false;
                    break;
                }
            }
            if (sorted) break; 

            int minSum = nums[0] + nums[1];
            int idx = 0;
            for (int i = 1; i + 1 < nums.size(); i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    idx = i;
                }
            }

            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);  
            op++;
        }

        return op;
    }
};
