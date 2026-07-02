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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return {};
        }

        queue<TreeNode*> q;
        vector<vector<int>> ans; 
        vector<int> temp;

        q.push(root);

        while(q.size()){
            int n = q.size();

            while(n--){
                TreeNode* f = q.front();

                temp.push_back(q.front()->val);

                if(f->left){
                    q.push(f->left);
                }
                if(f->right){
                    q.push(f->right);
                }

                q.pop();
            }

            ans.push_back(temp);
            temp.clear();
        }

        return ans;
    }
};
