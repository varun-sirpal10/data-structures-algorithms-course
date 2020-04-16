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
    int maxPathSum(TreeNode* root) {
        int maxGlobal = INT_MIN;
        maxSum(root,maxGlobal);
        return maxGlobal;
    }
    
    int maxSum(TreeNode* root, int &maxGlobal){
        
        if(root==NULL){
            return 0;
        }
        
        int leftMax = maxSum(root->left,maxGlobal);
        int rightMax = maxSum(root->right,maxGlobal);
        
        leftMax = max(0,leftMax);
        rightMax = max(0,rightMax);
        
        int mereThrough = leftMax + rightMax + root->val;
        
        maxGlobal = max(maxGlobal,mereThrough);
        
        return max(leftMax,rightMax) + root->val;
    }
};