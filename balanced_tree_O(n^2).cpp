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
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        bool leftRes = isBalanced(root->left);
        bool rightRes = isBalanced(root->right);
        
        return leftRes and rightRes and abs(rh-lh)<=1;   
    }
    
    int height(TreeNode* root) {
        if (root == NULL) {
            return -1;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        int totalHeight = max(leftHeight, rightHeight) + 1;
        return totalHeight;
    }
};