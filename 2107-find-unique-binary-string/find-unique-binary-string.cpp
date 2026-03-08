class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int a = nums.size();
        string ans = "";
        
        for(int i = 0; i < a; i++){
            if(nums[i][i] == '0')
                ans += '1';
            else
                ans += '0';
        }
        
        return ans;
    }
};