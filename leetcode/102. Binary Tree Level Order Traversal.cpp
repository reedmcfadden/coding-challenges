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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        int level = 1;
        
        levelOrderUtil(root, level, res);
            
        return res;
    }
    
    void levelOrderUtil(TreeNode* current, int level, vector<vector<int>>& res) {
        // if the node is nullptr, do nothing and return
        if (current == nullptr) {
            return;
        }
        
        // add a new level every time we descend
        if (level > res.size()) {
            vector<int> newLevel;
            res.push_back(newLevel);
        }
        
        // add the new value to its respective level in the tree
        res[level - 1].push_back(current->val);
        
        // continue to recurse, left then right
        levelOrderUtil(current->left, level + 1, res);
        levelOrderUtil(current->right, level + 1, res);
    }
};
