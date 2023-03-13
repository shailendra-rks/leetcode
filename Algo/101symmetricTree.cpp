/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool areImages(TreeNode* left, TreeNode* right){
        if(left->val != right->val) return false;

        //left-left to right-right
        bool LtoR = false;
        if(!left->left && !right->right){
            LtoR = true;
        }
        else if(left->left && right->right){
            LtoR = areImages(left->left, right->right);;
        }

        //left-right to right-left
        bool RtoL = false;
        if(LtoR){
            if(!left->right && !right->left){
                RtoL = true;
            }
            else if(left->right && right->left){
                RtoL = areImages(left->right, right->left);;
            }
        }
        if(LtoR && RtoL) return true;
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right){
            return true;
        }
        if(root->left && root->right){
            return areImages(root->left, root->right);
        }
        return false;
    }
};