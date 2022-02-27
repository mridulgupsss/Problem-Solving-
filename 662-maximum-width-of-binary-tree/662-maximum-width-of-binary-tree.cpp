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
    int widthOfBinaryTree(TreeNode* root) {
        
        //we use bfs to traverse the nodes
        queue<pair<TreeNode*,unsigned long long int>> q;
        //pair.first is the node  and pair.second (id) is a number  
        //it denotes the number of nodes in the complete tree that can be present  upto current level
        q.push({root,1});
        int res=0;
        int curr;
        while(!q.empty())
        {
            int size=q.size();
            if(size==1)
            {
                //rename the pair.second value as 1 now this sub tree can be considered as seperate tree
                q.push({q.front().first,1});
                q.pop();
            }
            curr=q.back().second-q.front().second +1;
            //update the maximum result with   the current level result
            res=max(res,curr );
            for(int i=0;i<size;i++)
            {
                auto [front,id]=q.front();
                q.pop();
                //if left child exists then the id would be 2*current node id
                if(front->left)
                    q.push({front->left,2*id});
                //if right child exists then the id would be 2*current node id +1 
                if(front->right)
                    q.push({front->right,2*id+1});
            }
        }
        return res;
        
    }
};