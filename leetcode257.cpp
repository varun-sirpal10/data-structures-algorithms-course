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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root==NULL){
            return result;
        }
        
        helper(root,result,"");
        return result;
    }
    
    void helper(TreeNode* root, vector<string>& result, string path){
        path += to_string(root->val);
        if(root->left != NULL or root->right != NULL){
            path += "->";
        }
        else{
            result.push_back(path);
            return;
        }
        
        if(root->left != NULL) {
            helper(root->left,result,path);
        }
        if(root->right != NULL){
            helper(root->right,result,path);   
        }
    }
};