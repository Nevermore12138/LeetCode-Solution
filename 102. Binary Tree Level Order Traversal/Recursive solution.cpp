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
        ord(root, 0, result);
        return result;
    }

    void ord(TreeNode* node, int level, vector<vector<int>>& res){
        if(!node)
            return;
        if(res.size()==level){
            vector<int> temp;
            res.push_back(temp);
        } 
        res[level].push_back(node->val);
        ord(node->left, level+1, res);
        ord(node->right, level+1, res);
    }
};
