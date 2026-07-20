/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int solve(TreeNode* root, int &cnt){
        if(!root)return INT_MIN;

        int l=solve(root->left, cnt);
        int r=solve(root->right, cnt);

        int maxi=max({root->val, l, r});

        if(maxi==root->val)cnt++;

        return maxi;
    }
public:
    int countDominantNodes(TreeNode* root) {
        int cnt=0;
        solve(root, cnt);
        return cnt;
    }
};