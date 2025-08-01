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
    void dfs(TreeNode* node, int sum, int target, vector<int>& path, vector<vector<int>>& res) {
        if (!node) return;
        path.push_back(node->val);

        if (!node->left && !node->right && sum + node->val == target) {
            res.push_back(path);
        }
        else{
            dfs(node->left, sum + node->val, target, path, res);
            dfs(node->right, sum + node->val, target, path, res);
        }
        path.pop_back(); 
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, 0, targetSum, path, res);
        return res;
    }
};