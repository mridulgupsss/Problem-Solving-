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
    int helper(TreeNode * root, int &mx){
        if(root==NULL) return 0;
        int lh = helper(root->left, mx);
        int rh = helper(root->right, mx);
        mx=max(mx, lh+rh+1);
        return max(lh, rh)+1;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans =INT_MIN;
        int height = helper(root, ans);
        return ans-1;// because of edges
    }
};