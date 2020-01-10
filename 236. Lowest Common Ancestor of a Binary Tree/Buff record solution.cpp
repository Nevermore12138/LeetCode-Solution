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
private:
    unordered_map<TreeNode*, int> nodeInRec;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int k = 0;
        vector<TreeNode*> pAncestors;
        vector<TreeNode*> qAncestors;
        stack<TreeNode*> nodeStack;
        TreeNode* temp = root;
        while(temp || !nodeStack.empty()){
            if(temp){
                nodeStack.push(temp);
                temp = temp->left;
            }
            else{
                temp = nodeStack.top();
                nodeInRec.insert({temp, ++k});
                nodeStack.pop();
                temp = temp->right;
            }
        }
        getAncestor(root, p, pAncestors);
        getAncestor(root, q, qAncestors);
        set<TreeNode*> s(pAncestors.cbegin(), pAncestors.cend());
        int i;
        for(i=qAncestors.size()-1; i>=0; --i){
            if(s.find(qAncestors[i]) != s.end())
                break;
        }
        return qAncestors[i];
    }

    void getAncestor(TreeNode* root, TreeNode* target, vector<TreeNode*>& buff){
        buff.push_back(root);
        if(root==target)
            return ;
        if(nodeInRec[target]<nodeInRec[root])
            getAncestor(root->left, target, buff);
        else
            getAncestor(root->right, target, buff);
    }
};
