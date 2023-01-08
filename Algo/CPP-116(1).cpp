// 116. Populating Next Right Pointers in Each Node
// not a perfect solution on the way when tree is not perfect
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
    void connectChild(Node* lo, Node* hi){
        Node* one;
        Node* two;
        if(lo->right){
            one = lo->right;
        }
        else if(lo->left){
            one = lo->left;
        }
        if(hi->left){
            two = hi->left;
        }
        else if(hi->right){
            two = hi->right;
        }
        if(one && two){
            one->next = two;
            connectChild(one,two);
        }
    }

    Node* connect(Node* root) {
        if(root != NULL){
            if(root->left && root->right){
                root->left->next = root->right;
                connectChild(root->left, root->right);
            }
            root->left = connect(root->left);
            root->right = connect(root->right);
        }
        return root;
    }
};