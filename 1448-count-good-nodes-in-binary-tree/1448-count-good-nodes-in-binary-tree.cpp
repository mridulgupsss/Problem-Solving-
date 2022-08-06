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
    int helper(TreeNode* root, int mx){
        if(root==NULL) return 0;
        
        int ans_l_r = helper(root->left, max(mx, root->val)) + helper(root->right, max(mx, root->val));
        
        if(root->val>=mx){
            return ans_l_r+1;
        }
        else return ans_l_r;
    }
    int goodNodes(TreeNode* root) {
        
        return helper(root, INT_MIN);
    }
};