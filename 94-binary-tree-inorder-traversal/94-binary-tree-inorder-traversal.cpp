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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        vector<int> l = inorderTraversal(root->left);
        for(auto val:l){
            ans.push_back(val);
        }
        ans.push_back(root->val);
        
        vector<int> r = inorderTraversal(root->right);

        for(auto val:r){
            ans.push_back(val);
        }
        return ans;
        
    }
};