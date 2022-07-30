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
 TreeNode* prev;
TreeNode * helper(TreeNode* root){
if(!root) return root;
            TreeNode* lnode = helper(root->left);
        TreeNode* rnode =  helper(root->right);
    TreeNode* head=lnode;
if(head){
     while(head->right!=NULL){
     head=head->right;
 }
    head->right=rnode;
}
    
if(lnode) root->right=lnode;
    else root->right=rnode;
    
    root->left=NULL;
    return root;
    
}
    void flatten(TreeNode* root) {
             if(root==NULL)return ;
            root=helper(root);
        

    }
};