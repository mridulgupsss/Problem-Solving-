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
class CBTInserter {
public:
    queue<TreeNode*> q;
    TreeNode* head=NULL;
    CBTInserter(TreeNode* root) {
        head=root;
        q.push(root);
        while(true){
      TreeNode* rem = q.front();
        if(rem->left==NULL){
            break;
        }
        else{
           q.push(rem->left);
            if(rem->right==NULL) {
                break;
            }
            else{
                q.push(rem->right);
                 q.pop();
            }

        }
}
        
    }
    
    int insert(int val) {
      
while(true){
      TreeNode* rem = q.front();
        if(rem->left==NULL){
             rem->left=new TreeNode(val);
             q.push(rem->left);
            return rem->val;
        }
        else{
            q.pop();
            if(rem->right==NULL) {
                rem->right=new TreeNode(val);
                q.push(rem->right);
                return rem->val;
            }

        }
}
    
    }
    
    TreeNode* get_root() {
        return head;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */