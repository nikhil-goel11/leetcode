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
int countleft_height(TreeNode*root){
     if(root==nullptr)return 0;
    int  cnt = 0;
    while(root!=nullptr){
    cnt++;
    root=root->left;
  }
    return cnt;
}
int countright_height(TreeNode*root){
    if(root==nullptr)return 0;
    int cnt = 0;
    while(root!=nullptr){
    cnt++;
    root=root->right;
  }
    return cnt;
    }

    int countNodes(TreeNode* root) {
    if(root==nullptr)return 0;
    int lh = countleft_height(root->left);
    int rh = countright_height(root->right);
    if(lh==rh)return ((1<<(lh+1))-1);
    return 1+countNodes(root->left)+countNodes(root->right);
    }
};