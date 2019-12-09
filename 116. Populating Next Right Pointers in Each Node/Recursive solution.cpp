/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        Node* leftSubTree = root->left;
        Node* rightSubTree = root->right;
        while(leftSubTree && rightSubTree){
            leftSubTree->next = rightSubTree;
            leftSubTree = leftSubTree->right;
            rightSubTree = rightSubTree->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
    
};
