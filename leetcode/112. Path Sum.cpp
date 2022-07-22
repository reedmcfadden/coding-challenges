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
    bool hasPathSum(TreeNode* root, int targetSum) {
        int currentSum = 0;
        return DFSHasSum(root, targetSum, currentSum);
    }
    
    bool DFSHasSum(TreeNode* current, int& targetSum, int currentSum) {
        if (current == nullptr) {
            return false;
        }
        
        currentSum += current->val;
        
        // if the node is a leaf, and the targetSum is met, return true
        if (current->left == nullptr && current->right == nullptr && currentSum == targetSum) {
            return true;
        }
        
        return DFSHasSum(current->left, targetSum, currentSum) 
            || DFSHasSum(current->right, targetSum, currentSum);
    }
};
