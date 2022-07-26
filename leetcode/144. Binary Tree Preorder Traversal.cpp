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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorderHelper(res, root);
        return res;
    }
    
    void preorderHelper(vector<int>& preorderVector, TreeNode* current) {
        if (current == nullptr) {
            return;
        }
        
        preorderVector.push_back(current->val);
        preorderHelper(preorderVector, current->left);
        preorderHelper(preorderVector, current->right);
    }
};
