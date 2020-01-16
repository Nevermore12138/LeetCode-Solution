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
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> nodeStack;
        pair<TreeNode*, int> currPair{root, 1};
        int level = 0;
        while(currPair.first || !nodeStack.empty()){
            if(currPair.first){
                nodeStack.push(currPair);
                currPair=make_pair(currPair.first->left, currPair.second+1);
            } 
            else{
                currPair = nodeStack.top();
                nodeStack.pop();
                level = max(level, currPair.second);
                currPair = make_pair(currPair.first->right, currPair.second+1);
            }
        }
        return level;     
    }
};
