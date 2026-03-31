class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int len = n + m - 1;

        string word(len, '?');
        vector<bool> locked(len, false);

        // Step 1: Apply 'T'
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                        locked[i + j] = true; // mark locked
                    } else {
                        return "";
                    }
                }
            }
        }

        // Step 2: Fill remaining with 'a'
        for (int i = 0; i < len; i++) {
            if (word[i] == '?') word[i] = 'a';
        }

        // Step 3: Fix 'F'
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;

                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    bool changed = false;

                    // try to break without touching locked positions
                    for (int j = m - 1; j >= 0; j--) {
                        int pos = i + j;

                        if (!locked[pos]) {
                            for (char c = 'a'; c <= 'z'; c++) {
                                if (c != str2[j]) {
                                    word[pos] = c;
                                    changed = true;
                                    break;
                                }
                            }
                        }

                        if (changed) break;
                    }

                    if (!changed) return ""; // cannot break safely
                }
            }
        }

        return word;
    }
};