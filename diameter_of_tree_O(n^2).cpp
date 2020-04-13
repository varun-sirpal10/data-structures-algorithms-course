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
    int diameterOfBinaryTree(TreeNode* root) {
         if(root == NULL){
             return 0;
         }
        
        int h1 = height(root->left);
        int h2 = height(root->right);
        
        int op1 = h1 + h2;
        int op2 = diameterOfBinaryTree(root->left);
        int op3 = diameterOfBinaryTree(root->right);
        
        return max(op1,max(op2,op3));
    }
    
    int height(TreeNode* root) {

        if(root == NULL){
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return max(leftHeight,rightHeight) + 1;
    }	
};