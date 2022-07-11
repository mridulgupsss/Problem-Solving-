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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        queue<TreeNode> q;
        q.push(*root);
        while(q.size()>0)
        {
            int flag=0;
            int sz=q.size();
            while(sz-- >0){
                TreeNode node=q.front(); q.pop(); 
                if(flag==0)
                {
                    ans.push_back(node.val);
                    flag=1;
                }
                if(node.right!=NULL) q.push(*node.right);
                if(node.left!=NULL) q.push(*node.left);
            }
            
            
        }
        return ans;
    }
};