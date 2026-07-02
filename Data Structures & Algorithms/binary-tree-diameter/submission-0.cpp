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

    int recursion(TreeNode* root, int & maxm){
        if(!root){
            return -1;
        }

        int left = 1 + recursion(root->left, maxm);


        int right = 1 + recursion(root->right, maxm);

        maxm = max(maxm, left+right);


        return max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxm = 0;
        recursion(root, maxm);
        return maxm;

    }
};