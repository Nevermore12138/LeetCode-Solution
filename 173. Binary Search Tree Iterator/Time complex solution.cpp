/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    TreeNode *rootNode, *targetNode, *parNode;
    int minNum;
public:
    BSTIterator(TreeNode* root) {
        rootNode = root;
    }
    
    /** @return the next smallest number */
    int next() {
        parNode = rootNode;
        targetNode = rootNode;
        while(targetNode->left){
            parNode = targetNode;
            targetNode = targetNode->left;
        }
        minNum = targetNode->val; 
        if(targetNode == rootNode)
            rootNode = rootNode->right;
        else
            parNode->left = targetNode->right;
        return minNum;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(rootNode)
            return true;
        else
            return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
