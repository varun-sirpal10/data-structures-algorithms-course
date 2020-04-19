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
    TreeNode* searchBST(TreeNode* root, int key) {
        if(root == NULL){
		    return NULL;
        }

        if(root->val == key){
            return root;
        }

        if(key > root->val){
            return searchBST(root->right,key);
        }
        else{
            return searchBST(root->left,key);
        }
    }
};