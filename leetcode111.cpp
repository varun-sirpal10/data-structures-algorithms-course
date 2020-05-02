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
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        return levelOrderNewLineBetter(root);
    }
    
    int levelOrderNewLineBetter(TreeNode* root) {

        queue<TreeNode*> q;

        q.push(root);
        
        int depth = 1;

        while (!q.empty()) {

            int len = q.size();

            for (int i = 0; i < len; i++) {

                TreeNode* temp = q.front();
                q.pop();

                if(temp->left==NULL and temp->right==NULL){
                    return depth;
                }
                else if(i==len-1){
                    depth++;
                }

                if (temp->left != NULL) {
                    q.push(temp->left);
                }

                if (temp->right != NULL) {
                    q.push(temp->right);
                }
            }
        }
        
        return depth;
    }
};