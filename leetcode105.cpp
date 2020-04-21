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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start = 0;
        return buildTreeFromPreorderInorder(preorder,inorder,start,preorder.size()-1);
    }
    
    int preIndex = 0;

    TreeNode* buildTreeFromPreorderInorder(vector<int>& pre, vector<int>& in, int start, int end){
        
        if(start > end){
            return NULL;
        }
	
        TreeNode* root = new TreeNode(pre[preIndex]);

        int mid;

        for(int i=start;i<=end;i++){
            if(in[i] == pre[preIndex]){
                mid = i;
                break;
            }
        }

        preIndex++;

        root->left = buildTreeFromPreorderInorder(pre,in,start,mid-1);
        root->right = buildTreeFromPreorderInorder(pre,in,mid+1,end);

        return root;
    }
};