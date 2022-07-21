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
    bool isSymmetric(TreeNode* root) {
        return symmetricDFS(root->left, root->right);
    }
    
    bool symmetricDFS(TreeNode* left, TreeNode* right) {
        // if both are nullptr, they are equal. return true because they have no children
        // else if both weren't nullptr, but one is, return false
        // else if neither are nullptr, but vals are not equal, return false
        if (left == nullptr && right == nullptr) {
            return true;
        }
        else if (left == nullptr || right == nullptr) {
            return false;
        }
        else if (left->val != right->val) {
            return false;
        }
        
        // all nodes were mirrored and equal in value, return true
        return symmetricDFS(left->left, right->right) && symmetricDFS(left->right, right->left);
    } 
};
