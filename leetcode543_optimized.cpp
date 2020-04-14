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
    
    class DiaHeight{
        public:
        int diameter;
        int height;
    };
    
    int diameterOfBinaryTree(TreeNode* root) {
        DiaHeight result = diameterOptimized(root);
        return result.diameter;
    }
    
    DiaHeight diameterOptimized(TreeNode* root){
        DiaHeight val;
        
        if(root == NULL){
            val.diameter = 0;
            val.height = -1;
            return val;
        }
        
        DiaHeight leftPair = diameterOptimized(root->left);
        DiaHeight rightPair = diameterOptimized(root->right);
        
        int leftDia = leftPair.diameter;
        int rightDia = rightPair.diameter;
        
        int leftHeight = leftPair.height;
        int rightHeight = rightPair.height;
        
        int meraDia = leftHeight + rightHeight + 2;
        
        int totalDia = max(meraDia,max(leftDia,rightDia));
        
        int totalHeight = max(leftHeight,rightHeight) + 1;
        
        val.diameter = totalDia;
        val.height = totalHeight;
        return val;
    }
};