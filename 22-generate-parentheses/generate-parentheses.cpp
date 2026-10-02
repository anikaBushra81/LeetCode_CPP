class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;

        function<void(int, int)> backtrack = [&](int open, int close) {
            // A complete valid combination
            if (open == n && close == n) {
                ans.push_back(s);
                return;
            }

            // Add opening parenthesis
            if (open < n) {
                s.push_back('(');
                backtrack(open + 1, close);
                s.pop_back();
            }

            // Add closing parenthesis only when valid
            if (close < open) {
                s.push_back(')');
                backtrack(open, close + 1);
                s.pop_back();
            }
        };

        backtrack(0, 0);
        return ans;
    }
};