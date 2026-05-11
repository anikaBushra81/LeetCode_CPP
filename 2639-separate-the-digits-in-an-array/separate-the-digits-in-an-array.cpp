class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> answer;
        
        for (int num : nums) {
            string str = to_string(num);
            
            for (char ch : str) {
                answer.push_back(ch - '0');
            }
        }
        
        return answer;
    }
};