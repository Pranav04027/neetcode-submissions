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
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int>ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            TreeNode* rightmost = q.front();
            ans.push_back(rightmost->val);


            while(n--){
                TreeNode* f = q.front();
                if(f->right){
                    q.push(f->right);
                }
                if(f->left){
                    q.push(f->left);
                }
                q.pop();
            }
        }
        return ans;
    }
};