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
public:
    void dfs(TreeNode* root, int & ans, int maxm){
        if(root == nullptr){
            return;
        }

        if(root->val >= maxm){
            ans = ans + 1;
        }

        maxm = max(maxm, root->val);

        dfs(root->left, ans, maxm);
        dfs(root->right, ans, maxm);
    }

    int goodNodes(TreeNode* root) {
        int ans = 0;
        int maxm = INT_MIN;

        dfs(root, ans, maxm);

        return ans;

    }
};