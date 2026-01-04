class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        
        for (int num : nums) {
            vector<int> divisors;
            
            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    divisors.push_back(i);
                    if (i != num / i)
                        divisors.push_back(num / i);
                }
                if (divisors.size() > 4) break; // no need to continue
            }
            
            if (divisors.size() == 4) {
                int sum = 0;
                for (int d : divisors) sum += d;
                result += sum;
            }
        }
        
        return result;
    }
};
