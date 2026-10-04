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
int findVal(TreeNode* root, int& maxi){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) {
            maxi=max(maxi, root->val);
            return root->val;
        }
        int left=max(0, findVal(root->left, maxi));
        int right=max(0,findVal(root->right, maxi));
        int sum=root->val + left + right;
        maxi=max(maxi, sum);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        findVal(root, maxi);
        return maxi;
    }
};