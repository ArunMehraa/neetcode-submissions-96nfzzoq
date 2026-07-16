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
    TreeNode* solve(int& ind,int left,int right,vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>&mp){
        if(left>right)return NULL;
        if(ind==preorder.size())return NULL;
        int pos = mp[preorder[ind]];
        TreeNode* node = new TreeNode(preorder[ind]);
        ind++;
        node->left = solve(ind,left,pos-1,preorder,inorder,mp);
        node->right = solve(ind,pos+1,right,preorder,inorder,mp);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        int n = inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int ind=0;
        return solve(ind,0,n-1,preorder,inorder,mp);
    }
};
