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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty())
            return NULL;
        int rootVal = postorder.back();
        TreeNode* rootNode = new TreeNode(rootVal);
        auto rootPos = inorder.begin();
        while(*rootPos!=rootVal)
            ++rootPos;

        vector<int> leftSubInRes(inorder.begin(), rootPos);
        int leftSubSize = leftSubInRes.size();
        auto leftSubPosInPost = postorder.begin();
        leftSubPosInPost += leftSubSize;
        vector<int> leftSubPostRes(postorder.begin(), leftSubPosInPost);
        rootNode->left = buildTree(leftSubInRes, leftSubPostRes);

        vector<int> rightSubInRes(++rootPos, inorder.end());
        vector<int> rightSubPostRes(leftSubPosInPost, --postorder.end());
        rootNode->right = buildTree(rightSubInRes, rightSubPostRes);

        return rootNode;
    }
};
