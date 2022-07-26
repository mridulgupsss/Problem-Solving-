/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return root;
        else if(root->val==p->val || root->val==q->val) return root ;
        else{
            TreeNode * lnode = lowestCommonAncestor(root->left, p, q);
            TreeNode * rnode = lowestCommonAncestor(root->right, p, q);
            if(lnode&& rnode ) return root;
            else if(!lnode && !rnode) return NULL;
            else if(lnode) return lnode ;
            else return rnode;
        }

    }
};