/*
// 116. Populating Next Right Pointers in Each Node
// perfect binary tree where all leaves are on the same level
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
        if(root != NULL){

            // Perfect Binary tree
            if(root->left){
                root->left->next = root->right;
            }

            // All leaves on same level
            if(root->next && root->left){
                root->right->next = root->next->left;
            }
            root->left = connect(root->left);
            root->right = connect(root->right);
        }
        return root;
    }
};