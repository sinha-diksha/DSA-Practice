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
    int findDiameter(TreeNode* root, int& diameter){
        if(root==NULL) return 0;
        int lH=findDiameter(root->left, diameter);
        int rH=findDiameter(root->right, diameter);
        diameter=max(diameter, lH+rH);
        return 1+max(lH,rH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        findDiameter(root, diameter);
        return diameter;     
    }
};

// TC: O(n)
// SC: O(n)