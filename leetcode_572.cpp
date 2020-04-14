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
        
        if(s==NULL or t==NULL){
            return false;
        }
        
        if(isSameTree(s,t)){
            return true;
        }
        
        bool leftRes = isSubtree(s->left,t);
        bool rightRes = isSubtree(s->right,t);
        
        return leftRes or rightRes;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p==NULL and q==NULL){
            return true;
        }
        
        if(p==NULL or q==NULL or p->val != q->val){
            return false;
        }
        
        bool leftRes = isSameTree(p->left,q->left);
        bool rightRes = isSameTree(p->right,q->right);
        
        if(leftRes and rightRes){
            return true;
        }
        
        return false;
    }
};