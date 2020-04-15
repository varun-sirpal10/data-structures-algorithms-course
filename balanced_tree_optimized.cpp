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
    class BalancedHeight{
        public:
        bool check;
        int height;
    };
    
    bool isBalanced(TreeNode* root) {
        BalancedHeight result = balancedTree(root);
        return result.check;
    }
    
    BalancedHeight balancedTree(TreeNode* root){
        BalancedHeight val;
        
        if(root == NULL){
            val.check = true;
            val.height = -1;
            return val;
        }
        
        BalancedHeight leftPair = balancedTree(root->left);
        BalancedHeight rightPair = balancedTree(root->right);
        
        if(!leftPair.check or !rightPair.check){
            val.check = false;
            return val;
        }
        
        int lh = leftPair.height;
        int rh = rightPair.height;
        
        val.height = max(lh,rh) + 1;
        
        if(abs(lh - rh) <= 1){
            val.check = true;
        }
        else{
            val.check = false;
        }
        
        return val;
    }
};