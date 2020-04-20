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
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inOrderTraversal(root,k,ans);
        
        return ans;
    }
    
    void inOrderTraversal(TreeNode* root, int &k, int &ans){
        if(root == NULL){
            return;
        }
        
        inOrderTraversal(root->left,k,ans);
        
        k--;
        if(k == 0){
            ans = root->val;
        }   
        
        inOrderTraversal(root->right,k,ans);
    }
};