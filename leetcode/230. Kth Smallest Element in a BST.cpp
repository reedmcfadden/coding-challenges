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
    int kthSmallest(TreeNode* root, int k) {
        int current = 0;
        int res = 0;
        inOrderSearchForKthValue(root, k, current, res);
        return res;
    }
    
    bool inOrderSearchForKthValue(TreeNode* node, int k, int& current, int& res) {
        if (node == nullptr) {
            return false;
        }
        
        if (inOrderSearchForKthValue(node->left, k, current, res)) {
            return true;
        }
        
        ++current;
        if (current == k) {
            res = node->val;
            return true;
        }
        
        if (inOrderSearchForKthValue(node->right, k, current, res)) {
            return true;
        }
        
        return false;
    }
};
