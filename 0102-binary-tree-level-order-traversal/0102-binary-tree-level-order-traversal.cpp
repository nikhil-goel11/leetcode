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
        if(root==nullptr){
            return {};
        }
        vector<vector<int>>res;
        // if(!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int n = q.size();

            while(n--){
                TreeNode* front = q.front(); 
                q.pop();
                level.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front-> right) q.push(front->right);
            }
            res.push_back(level);
        }
        return res;
    }
};