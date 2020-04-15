/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool check = true;
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        height(root);
        return check;
    }
    
    int height(TreeNode* root) {
        if (root == NULL) {
            return -1;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        if(abs(leftHeight - rightHeight) > 1) check = false;

        int totalHeight = max(leftHeight, rightHeight) + 1;
        return totalHeight;
    }
};