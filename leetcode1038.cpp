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
    TreeNode* bstToGst(TreeNode* root) {
        int val=0;
        inOrderTraversal(root,val);
        return root;
    }
    
    void inOrderTraversal(TreeNode* root, int &val){
        if(root == NULL){
            return;
        }
        
        inOrderTraversal(root->right,val);
        root->val += val;
        val = root->val;
        inOrderTraversal(root->left,val);
    }
};