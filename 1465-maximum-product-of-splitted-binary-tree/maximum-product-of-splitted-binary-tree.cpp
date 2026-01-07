class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long totalSum = 0;
    long long maxProd = 0;

    // First DFS: calculate total sum
    long long treeSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + treeSum(root->left) + treeSum(root->right);
    }

    // Second DFS: calculate subtree sums and max product
    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subSum = root->val + left + right;
        maxProd = max(maxProd, subSum * (totalSum - subSum));

        return subSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = treeSum(root);
        dfs(root);
        return maxProd % MOD;
    }
};
