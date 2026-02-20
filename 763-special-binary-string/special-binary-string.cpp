class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;
        int c = 0, start = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') c++;
            else c--;

            if (c == 0) {
                
                string inner = makeLargestSpecial(
                    s.substr(start + 1, i - start - 1)
                );
                
                parts.push_back("1" + inner + "0");
                start = i + 1;
            }
        }

       
        sort(parts.begin(), parts.end(), greater<string>());

       
        string result = "";
        for (string &p : parts) {
            result += p;
        }

        return result;
    }
};