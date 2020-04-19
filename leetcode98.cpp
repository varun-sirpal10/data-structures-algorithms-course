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
    bool isValidBST(TreeNode* root) {
        return isBST(root);
    }
    
    bool isBST(TreeNode* root, long minRange=LONG_MIN, long maxRange=LONG_MAX){
        if(root == NULL){
            return true;
        }
        
        bool leftBST = isBST(root->left,minRange,root->val);
        bool rightBST = isBST(root->right,root->val,maxRange);
        
        return leftBST and rightBST and root->val > minRange and root->val <             maxRange;
    }
};