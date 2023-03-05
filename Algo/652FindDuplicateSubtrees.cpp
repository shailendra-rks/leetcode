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
    int resolveDupSubtree(TreeNode* &root, unordered_map<int, int> &hash_set, unordered_map<string, int> &hash_string, vector<TreeNode*> &res){

        if(root == NULL){
            return 0;
        }

        string trio = to_string(resolveDupSubtree(root->left, hash_set, hash_string, res)) + "," + to_string(root->val) + "," + to_string(resolveDupSubtree(root->right, hash_set, hash_string, res));

        if(hash_string.count(trio)==0){
            hash_string[trio] = hash_string.size()+1;
        }
        int id = hash_string[trio];
        hash_set[id]++;
        if(hash_set[id] == 2){
            res.push_back(root);
        }
        return id;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<int, int> hash_set;
        unordered_map<string, int> hash_string;
        vector<TreeNode*> res;

        resolveDupSubtree(root, hash_set, hash_string, res);
        return res;
    }
};