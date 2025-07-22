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
    unordered_map<int, int> idx;
        TreeNode* build(vector<int>& inorder, int inL, int inR, vector<int>& postorder, int postL, int postR) {
   if (inL > inR || postL > postR) return nullptr;
     int rootVal = postorder[postR];
    int rootIdx = idx[rootVal];
   int leftSize = rootIdx - inL;
   TreeNode* root = new TreeNode(rootVal);
 root->left = build(inorder, inL, rootIdx - 1, postorder, postL, postL + leftSize - 1);
  root->right = build(inorder, rootIdx + 1, inR, postorder, postL + leftSize, postR - 1);
    return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); ++i) idx[inorder[i]] = i;
return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};