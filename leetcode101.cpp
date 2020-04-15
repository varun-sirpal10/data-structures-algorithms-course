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
    bool isSymmetric(TreeNode* root) {
        return helper(root,root);
    }
    
    bool helper(TreeNode* root1, TreeNode* root2){
        if(root1==NULL and root2==NULL){
            return true;
        }
        
        else if(root1== NULL or root2 == NULL){
            return false;
        }
        
        bool leftRes, rightRes;
        if(root1->val == root2->val){
            leftRes = helper(root1->left, root2->right);
            rightRes = helper(root1->right, root2->left);      
            return leftRes and rightRes;
        }    
        
        return false;
    }
};