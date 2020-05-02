/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        string path = "";
        rootToLeaf(root,path,sum);
        
        return sum;
    }
    
    void rootToLeaf(TreeNode* root,string path,int &sum){
        if(root == NULL){
            return;
        }
        
        path += to_string(root->val);
        
        if(root->left == NULL and root->right==NULL){
            sum += stoi(path);
        }
        
        rootToLeaf(root->left,path,sum);
        rootToLeaf(root->right,path,sum);
    }
};