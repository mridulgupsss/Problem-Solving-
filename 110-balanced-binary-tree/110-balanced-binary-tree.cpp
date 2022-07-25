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
    int helper(TreeNode* root){
        if(root==NULL)return 0;
        int lh = helper(root->left);
        if(lh==-2) return -2;
        int rh = helper(root->right);
        if(rh==-2) return -2;
        if(abs(lh-rh)>1) return -2;
        return max(lh, rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        // O(N) solution :
        return helper(root)==-2?false:true; 
        
    }
};