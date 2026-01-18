class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<long long>> rowSum(m, vector<long long>(n + 1, 0));
        vector<vector<long long>> colSum(m + 1, vector<long long>(n, 0));
        vector<vector<long long>> diag1(m + 1, vector<long long>(n + 1, 0));
        vector<vector<long long>> diag2(m + 1, vector<long long>(n + 2, 0));

        // Prefix sums
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
                colSum[i + 1][j] = colSum[i][j] + grid[i][j];
                diag1[i + 1][j + 1] = diag1[i][j] + grid[i][j];
                diag2[i + 1][j] = diag2[i][j + 1] + grid[i][j];
            }
        }

        for (int k = min(m, n); k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    long long target =
                        rowSum[i][j + k] - rowSum[i][j];

                    bool ok = true;

                    // Check rows
                    for (int r = 0; r < k && ok; r++) {
                        if (rowSum[i + r][j + k] - rowSum[i + r][j] != target)
                            ok = false;
                    }

                    // Check columns
                    for (int c = 0; c < k && ok; c++) {
                        if (colSum[i + k][j + c] - colSum[i][j + c] != target)
                            ok = false;
                    }

                    // Check diagonals
                    long long d1 = diag1[i + k][j + k] - diag1[i][j];
                    long long d2 = diag2[i + k][j] - diag2[i][j + k];

                    if (ok && d1 == target && d2 == target)
                        return k;
                }
            }
        }

        return 1; // At least 1x1 always works
    }
};
