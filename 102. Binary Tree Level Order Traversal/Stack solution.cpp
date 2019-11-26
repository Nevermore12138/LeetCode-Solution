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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> empty;
        stack<pair<TreeNode*, int>> nodeStack;
        pair<TreeNode*, int> tempPair{root, 0};
        while(tempPair.first || !nodeStack.empty()){
            if(tempPair.first){
                if(result.size() == tempPair.second){
                    result.push_back(empty);
                }
                result[tempPair.second].push_back(tempPair.first->val);
                nodeStack.push(tempPair);
                tempPair = make_pair(tempPair.first->left, tempPair.second+1);
            }
            else{
                tempPair = nodeStack.top();
                nodeStack.pop();
                tempPair = make_pair(tempPair.first->right, tempPair.second+1);
            }
        }
        return result;
    }
};
