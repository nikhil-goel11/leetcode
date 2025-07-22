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

vector<TreeNode*> build(int start, int end) {
          if (start > end) return {nullptr};
                  vector<TreeNode*> res;
                          for (int i = start; i <= end; ++i) {
for (auto left : build(start, i - 1)) {
      for (auto right : build(i + 1, end)) {
     TreeNode* root = new TreeNode(i);
  root->left = left;
  root->right = right;
  res.push_back(root);
  }
   }
   }
   return res;
   }
   public:
  vector<TreeNode*> generateTrees(int n) {
   if (n == 0) return {};
   return build(1, n);
    }
};