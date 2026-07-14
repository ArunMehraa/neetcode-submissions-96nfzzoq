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
    int solve(TreeNode* root, int curr_max){
        if(!root)return 0;
        if(root->val >= curr_max){
            return 1+solve(root->left,root->val)+solve(root->right,root->val);
        }
        else{
            return solve(root->left,curr_max)+solve(root->right,curr_max);
        }
    }
    int goodNodes(TreeNode* root) {
        return solve(root,INT_MIN);
    }
};
