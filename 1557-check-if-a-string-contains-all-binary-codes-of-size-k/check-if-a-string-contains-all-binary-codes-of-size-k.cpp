#include <unordered_set>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        
       
        int total = 1 << k;   
        
      
        if (n - k + 1 < total) return false;
        
        unordered_set<string> st;
        
        for (int i = 0; i <= n - k; i++) {
            st.insert(s.substr(i, k));
        }
        
        return st.size() == total;
    }
};