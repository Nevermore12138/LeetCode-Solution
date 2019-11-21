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
        stack<TreeNode *> nodeStack;
        vector<int> result;
        if(!root)
            return result;
        nodeStack.push(root);
        while(!nodeStack.empty())
        {
            TreeNode* tempNode = nodeStack.top();
            nodeStack.pop();
            result.push_back(tempNode->val);
            if(tempNode->right)
                nodeStack.push(tempNode->right);
            if(tempNode->left)
                nodeStack.push(tempNode->left);
            
        }
        return result;
    }

};
