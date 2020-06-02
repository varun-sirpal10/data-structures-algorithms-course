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
        
        int d = 0;
        heightModified(root,d);
        
        return d;
    }
    
    int heightModified(TreeNode* root, int &d) {

        if(root == NULL){
            return -1;
        }
        
        int leftHeight = heightModified(root->left,d);
        int rightHeight = heightModified(root->right,d);
        
        d = max(d,leftHeight + rightHeight + 2);

        return max(leftHeight,rightHeight) + 1;
    }
};