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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> nodeStack;
        vector<int> result;
        TreeNode* currNode = root;

        while(!nodeStack.empty() || currNode)
        {
            while(currNode)
            {
                nodeStack.push(currNode);
                currNode = currNode->left;
            }
            currNode = nodeStack.top();
            nodeStack.pop();
            result.push_back(currNode->val);
            currNode = currNode->right;
        }
        return result;
    }
};
