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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        
        if(s==NULL and t==NULL){
            return true;
        }
            
        if(s == NULL or t==NULL){
            return false;
        }
        
        if(s->val == t->val){
            bool leftRes = isSubtree(s->left,t->left);
            bool rightRes = isSubtree(s->right,t->right);

            return leftRes and rightRes;
        }
        
        bool left = isSubtree(s->left,t);
        bool right = isSubtree(s->right,t);

        return left or right;
    }
};