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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        deque<TreeNode*> q;
        if(!root->left && !root->right)
            return true;
        if(!root->left || !root->right || root->left->val!=root->right->val)
            return false;
        q.push_back(root->left);
        q.push_back(root->right);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz/2; ++i){
                TreeNode* beg = q[0];
                TreeNode* end = q[1];
                if(beg->left || end->right){
                	if((!beg->left||!end->right) || beg->left->val!=end->right->val)
                		return false;
                	q.push_back(beg->left);
                    q.push_back(end->right);
                }
                if(beg->right || end->left){
                	if((!beg->right||!end->left) || beg->right->val!=end->left->val)
                		return false;
                	q.push_back(beg->right);
                    q.push_back(end->left);
                }
                q.pop_front();
                q.pop_front();
            }
        }
        return true;
    }
};
