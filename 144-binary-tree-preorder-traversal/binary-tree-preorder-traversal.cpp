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
    void preOrderTraversalFunction(TreeNode* node, vector<int>& preOrder){
        if(node==NULL) return;
        preOrder.push_back(node->val);
        preOrderTraversalFunction(node->left, preOrder);
        preOrderTraversalFunction(node->right, preOrder);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preOrderTraversalFunction(root, ans);
        return ans;
    }
};