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
    bool isValidBST(TreeNode* root) {
        // perform inorder traversal. if the numbers are not ascending, return false
        vector<int> vals;
        
        inOrderTraverse(root, vals);
        
        for (int i = 1; i < vals.size(); ++i) {
            if (vals[i] <= vals[i - 1]) {
                return false;
            }
        }
        
        return true;
    }
    
    void inOrderTraverse(TreeNode* current, vector<int>& vals) {
        // base case
        if (current == nullptr) {
            return;
        }
        
        inOrderTraverse(current->left, vals);
        
        vals.push_back(current->val);
        
        inOrderTraverse(current->right, vals);
    }
};
