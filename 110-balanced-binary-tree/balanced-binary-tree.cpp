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
    pair<bool, int> isBal(TreeNode* root){
        if(root==NULL){
            return {true, 0};
        }

        pair<bool, int> l = isBal(root->left);
        pair<bool, int> r = isBal(root->right);
        if(l.first && r.first && abs(l.second-r.second)<=1){
            return {true, 1+max(l.second, r.second)};
        }
        return {false, 1+max(l.second, r.second)};
    }
    bool isBalanced(TreeNode* root) {
        pair<bool, int> val = isBal(root);
        return val.first;
    }
};