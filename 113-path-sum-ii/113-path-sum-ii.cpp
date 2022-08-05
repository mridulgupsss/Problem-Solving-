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
    void helper(TreeNode* root, int sum,vector<int> smallAns, vector<vector<int>> &ans)
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL)
        {
            if(sum-root->val==0) 
            {
                smallAns.push_back(root->val);
                ans.push_back(smallAns);
            }
            return;
        }
        smallAns.push_back(root->val);
        helper(root->left, sum-root->val, smallAns, ans);
        helper(root->right, sum-root->val, smallAns, ans);

        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
                vector<vector<int>> ans;
      vector<int> smallAns;
         helper(root, targetSum, smallAns, ans);
        return ans;
    }
};