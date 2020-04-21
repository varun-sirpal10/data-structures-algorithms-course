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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL){
            return false;    
        }
        
        if(root->left==NULL and root->right==NULL and root->val == sum){
            return true;
        }
        
        int myVal = root->val;
        
        bool leftRes = hasPathSum(root->left, sum - myVal);
        bool rightRes = hasPathSum(root->right, sum - myVal);
        
        return leftRes or rightRes;
    }
};