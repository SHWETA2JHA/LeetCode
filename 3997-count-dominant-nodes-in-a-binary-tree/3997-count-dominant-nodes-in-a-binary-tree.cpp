class Solution {
private:
    int solve(TreeNode* root, int &cnt) {
        if (!root) return INT_MIN;

        int leftMax = solve(root->left, cnt);
        int rightMax = solve(root->right, cnt);

        int subtreeMax = max({root->val, leftMax, rightMax});

        if (root->val == subtreeMax)
            cnt++;

        return subtreeMax;
    }

public:
    int countDominantNodes(TreeNode* root) {
        int cnt = 0;
        solve(root, cnt);
        return cnt;
    }
};