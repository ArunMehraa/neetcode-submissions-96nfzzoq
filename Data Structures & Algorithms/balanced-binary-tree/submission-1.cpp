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
    int height(TreeNode* root,int& res){
        if(!root)return 0;
        int left = height(root->left,res);
        int right = height(root->right,res);
        res = res && abs(right-left)<2;
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        int res = 1;
        height(root,res);
        return res;
    }
};
