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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1) return new TreeNode(val, root, NULL);
        queue<TreeNode*> q; q.push(root);
        int d=1;
        while(d<depth){
            int sz=q.size();
            while(sz--){
            if(d==depth-1){
                TreeNode* rem = q.front(); q.pop();
                TreeNode* l =  new TreeNode(val, rem->left, NULL);
                TreeNode* r = new TreeNode(val, NULL, rem->right);
                
                rem->left=l; rem->right=r;
            }
            else{
                TreeNode* rem = q.front(); q.pop();
                if(rem->left) q.push(rem->left);
                if(rem->right) q.push(rem->right);
            }
          }
            d++;
        }
            return root;
        }
    
};