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
    void helper(TreeNode* root, vector<TreeNode*> &ans){
        if(root==NULL) return ;
        ans.push_back(root);
        helper(root->left, ans);
        helper(root->right, ans);
        
    }
    void flatten(TreeNode* root) {
        
        vector<TreeNode*> ans;
        helper(root, ans);
        if(ans.size()==0 || ans.size()==1) return;
        TreeNode* curr=ans[0];
        for(int i=0; i<ans.size()-1; i++){
            TreeNode* next=ans[i+1];
            curr->left=NULL;
            curr->right=next;
            curr=next;
        }
        curr->right=NULL;
        
        
    }
};