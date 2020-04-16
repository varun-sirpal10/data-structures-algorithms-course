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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result = levelOrderSecond(root);
        
        return result;
    }
    
    vector<vector<int>> levelOrderSecond(TreeNode* root){
	
    vector<vector<int>> result;
        
    if(root == NULL){
        return result;
    }
        
	queue<TreeNode*> q;

	q.push(root);

	while(!q.empty()){

		int len = q.size();
        
        vector<int> ans;

		for(int i=0;i<len;i++){

			TreeNode* temp;

			temp = q.front();
			q.pop();
            
            ans.push_back(temp->val);

			if(temp->left != NULL){
				q.push(temp->left);
			}

			if(temp->right != NULL){
				q.push(temp->right);
			}
		}
		    result.push_back(ans);
	    }
        
        reverse(result.begin(),result.end());
        return result;
    }
};