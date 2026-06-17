class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        const long long CAP = (long long)1e15 + 5;

        vector<long long> len(n + 1, 0);

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (ch >= 'a' && ch <= 'z') {
                len[i + 1] = min(CAP, len[i] + 1);
            }
            else if (ch == '*') {
                len[i + 1] = max(0LL, len[i] - 1);
            }
            else if (ch == '#') {
                len[i + 1] = min(CAP, len[i] * 2);
            }
            else { // '%'
                len[i + 1] = len[i];
            }
        }

        if (k < 0 || k >= len[n]) return '.';

        long long idx = k;

        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];
            long long prevLen = len[i];
            long long curLen  = len[i + 1];

            if (ch >= 'a' && ch <= 'z') {
                if (idx == curLen - 1) {
                    return ch;
                }
                // otherwise idx stays the same in the previous string
            }
            else if (ch == '*') {
                // Characters before the deleted last character keep
                // the same indices.
            }
            else if (ch == '#') {
                if (prevLen > 0 && idx >= prevLen) {
                    idx -= prevLen;
                }
            }
            else { // '%'
                idx = prevLen - 1 - idx;
            }
        }

        return '.';
    }
};