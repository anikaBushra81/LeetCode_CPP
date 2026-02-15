class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        int c = 0;
        string result = "";
        
        while (i >= 0 || j >= 0 || c) {
            int sum = c;
            
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            
            result += (sum % 2) + '0';
            c = sum / 2;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};