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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        return pathSum(root->left, root->right, sum-root->val);
    }

    bool pathSum(TreeNode* tLeft, TreeNode* tRight, int sum){
        if(!tLeft && !tRight)
            return !sum;
        if(!tLeft)
            return pathSum(tRight->left, tRight->right, sum-tRight->val);
        if(!tRight)
            return pathSum(tLeft->left, tLeft->right, sum-tLeft->val);
        return pathSum(tLeft->left, tLeft->right, sum-tLeft->val) || pathSum(tRight->left, tRight->right, sum-tRight->val);
    } 
};
