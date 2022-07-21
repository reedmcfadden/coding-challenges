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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        inorderDFS(res, root);
        
        return res;
    }
    
private:
    void inorderDFS(vector<int>& res, TreeNode *curr) {
        if (curr == nullptr) {
            return;
        }

        inorderDFS(res, curr->left);

        res.push_back(curr->val);

        inorderDFS(res, curr->right);
    }
};
