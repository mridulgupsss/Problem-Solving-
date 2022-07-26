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
    bool helper(TreeNode* node1, TreeNode* node2){
        if(!node1 && !node2) return true;
        else if(!node1 && node2) return false;
        else if(!node2 && node1) return false;
        else{
            if(node1->val!=node2->val)return false;
            if(!helper(node1->left, node2->right) || (!helper(node1->right, node2->left))) return false;
            return true;
            
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return NULL;
        return helper(root->left, root->right);
    }
};