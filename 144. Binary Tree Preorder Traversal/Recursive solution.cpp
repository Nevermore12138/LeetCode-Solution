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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        result = preOrder(root, result);
        return result;
    }

    vector<int> preOrder(TreeNode* root, vector<int>& tempResult)
    {
        if(!root)
            return tempResult;
        tempResult.push_back(root->val);
        preOrder(root->left, tempResult);
        preOrder(root->right, tempResult);
        return tempResult;
    }
};
