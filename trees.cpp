#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int data) {
		this->val = data;
		this->left = NULL;
		this->right = NULL;
	}
};

TreeNode* builtTree(TreeNode* root) {

	int data;
	cin >> data;

	if (data == -1) {
		return NULL;
	}

	if (root == NULL) {
		root = new TreeNode(data);
	}

	root->left = builtTree(root->left);
	root->right = builtTree(root->right);

	return root;
}

void preOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	cout << root->val << " ";

	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	postOrder(root->left);
	postOrder(root->right);

	cout << root->val << " ";
}

int countNodes(TreeNode* root) {
	if (root == NULL) {
		return 1;
	}

	int leftCount = countNodes(root->left);
	int rightCount = countNodes(root->right);

	int total = leftCount + rightCount;
	return total;
}

// Inorder HomeWork
void inOrder(TreeNode* root) {
	if(root == NULL){
		return;
	}

	inOrder(root->left);

	cout<<root->val<<" ";
	
	inOrder(root->right);

}

int sumOfNodes(TreeNode* root) {
	if(root->left == NULL or root->right == NULL){
		return root->val;
	}

	int leftSum = 0, rightSum = 0;

	leftSum = sumOfNodes(root->left);
	rightSum = sumOfNodes(root->right);

	int total = leftSum + rightSum + root->val;

	return total;
}

bool search(TreeNode* root, int key) {

	if(root == NULL){
		return false;
	}

	if(key == root->val){
		return true;
	}

	bool resLeft = search(root->left, key);
	bool resRight = search(root->right, key);

	if(resLeft or resRight){
		return true;
	}

	return false;
}

int height(TreeNode* root) {

	if(root == NULL){
		return -1;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	return max(leftHeight,rightHeight) + 1;
}	

int replaceNodesWithSumOfChildren(TreeNode* root){
	if(root == NULL){
		return 0;
	}

	if(root->left == NULL and root->right == NULL){
		return root->val;
	}

	int leftSum = replaceNodesWithSumOfChildren(root->left);
	int rightSum = replaceNodesWithSumOfChildren(root->right);

	int prevRoot = root->val;
	int total = leftSum + rightSum;
	root->val = total;

	return total + prevRoot;
}

void levelOrderFirst(TreeNode* root){

	queue<TreeNode*> q;

	q.push(root);

	while(!q.empty()){

		TreeNode* temp = q.front();
		q.pop();

		cout<<temp->val<<" ";

		if(temp->left != NULL){
			q.push(temp->left);
		}

		if(temp->right != NULL){
			q.push(temp->right);
		}
	}

	cout<<endl;
}

void levelOrderSecond(TreeNode* root){
	
	queue<TreeNode*> q;

	q.push(root);

	while(!q.empty()){

		int len = q.size();

		for(int i=0;i<len;i++){

			TreeNode* temp;

			temp = q.front();
			cout<<temp->val<<" ";
			q.pop();

			if(temp->left != NULL){
				q.push(temp->left);
			}

			if(temp->right != NULL){
				q.push(temp->right);
			}
		}

		cout<<endl;
	}
}

void levelOrderNewLine(TreeNode* root){
	queue<pair<TreeNode*, int>> q;

	pair<TreeNode*,int> p(root,1);

	q.push(p);

	int currLevel = 1;

	while(!q.empty()){

		pair<TreeNode*, int> temp = q.front();
		q.pop();

		TreeNode* node = temp.first;
		int level = temp.second;

		if (currLevel==level)
		{
			cout<<node->val<<" ";
		}else
		{
			cout<<endl;
			currLevel = level;
			cout<<node->val<<" ";
		}

		if(node->left != NULL){
			pair<TreeNode*, int> p(node->left, level+1);

			q.push(p);
		}

		if(node->right != NULL){
			pair<TreeNode*,int> p(node->right,level+1);

			q.push(p);
		}
	}
}
    
vector<int> rightViewOfTree(TreeNode* root, vector<int> &result){
    
    if(root == NULL){
        return result;
    }
    
    queue<TreeNode*> q;
    
    q.push(root);
    
    while(!q.empty()){
        
        int len = q.size();
        
        for(int i=0;i<len;i++){
            
            TreeNode* temp = q.front();
            q.pop();
            
            if(i == len-1){
                result.push_back(temp->val);
            }
            
            if(temp->left != NULL){
                q.push(temp->left);
            }
            
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
    
    return result;
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    return rightViewOfTree(root,result);
}

void boundaryTraversalofTree(TreeNode* root){

	queue<TreeNode*> q;

	q.push(root);

	while(!q.empty()){
		int len = q.size();

		for(int i=0;i<len;i++){

			TreeNode* temp = q.front();
			q.pop();

			if(i==0 and (temp->left!=NULL and temp->right!=NULL)){
				cout<<temp->val<<" ";
			}

			else if(temp->left == NULL and temp->right==NULL and i != len-1){
				cout<<temp->val<<" ";
			}

			if(temp->left != NULL){
				q.push(temp->left);
			}

			if(temp->right != NULL){
				q.push(temp->right);
			}
		}
	}

	vector<int> res = rightSideView(root);
	reverse(res.begin(),res.end());

	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
}

void printNodesAtDistanceKFromRoot(TreeNode* root, int K){
	int count = 0;

	queue<TreeNode*> q;

	q.push(root);

	vector<int> result;

	while(!q.empty() and count <= K){

		int len = q.size();

		for(int i=0;i<len;i++){

			TreeNode* temp = q.front();
			q.pop();

			if(count == K){
				result.push_back(temp->val);
			}

			if(temp->left != NULL){
				q.push(temp->left);
			}

			if(temp->right != NULL){
				q.push(temp->right);
			}
		}
		count++;
	}

	for(int i=0;i<result.size();i++){
		cout<<result[i]<<" ";
	}
	cout<<endl;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL){
            return NULL;
        }
        
        if(root==p or root==q){
            return root;
        }
        
        TreeNode* leftLCA = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right,p,q);
        
        if(leftLCA!=NULL and rightLCA!=NULL){
            return root;
        }
        
        if(leftLCA==NULL and rightLCA==NULL){
            return NULL;
        }
        
        return leftLCA!=NULL ? leftLCA : rightLCA;
}

void leftBoundary(TreeNode* root){
	if(root == NULL){
		return;
	}

	if(root->left == NULL and root->right == NULL){
		return;
	}

	cout<<root->val<<" ";

	if(root->left != NULL){
		leftBoundary(root->left);
	}
	else{
		leftBoundary(root->right);
	}
}

void rightBoundary(TreeNode* root){
	if(root == NULL){
		return;
	}

	if(root->left == NULL and root->right == NULL){
		return;
	}

	if(root->right != NULL){
		rightBoundary(root->right);
	}
	else{
		rightBoundary(root->left);
	}

	cout<<root->val<<" ";
}

void printLeafNode(TreeNode* root){
	if(!root->left and !root->right){
		cout<<root->val<<" ";
	}

	printLeafNode(root->left);
	printLeafNode(root->right);
}

void printPreOrderWithNullValues(TreeNode* root){
	if(root == NULL){
		cout<<"NULL ";
		return;
	}

	cout<<root->val<<" ";
	printPreOrderWithNullValues(root->left);
	printPreOrderWithNullValues(root->right);
}

int main() {

	TreeNode* root = NULL;

	root = builtTree(root);

	// preOrder(root);
	// cout << endl;

	// postOrder(root);
	// cout << endl;

	// cout << countNodes(root) << endl;

	// inOrder(root);
	// cout<<endl;

	// cout<<sumOfNodes(root)<<endl;

	// cout<<search(root,13)<<endl;

	// cout<<height(root)<<endl;

	// int result = replaceNodesWithSumOfChildren(root);
	// cout<<result<<endl;
	// preOrder(root);

	// levelOrderFirst(root);

	// levelOrderSecond(root);

	// levelOrderNewLine(root);

	// boundaryTraversalofTree(root);

	// printNodesAtDistanceKFromRoot(root,2);

	printPreOrderWithNullValues(root);

	return 0;
}

// Input Tree
// 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1

// 1 -1 2 3 -1 5 6 -1 -1 7 -1 -1 4 -1 -1

// Balanced Input
// 1 2 -1 -1 3 -1 4 -1 6 -1 -1

// Left View
// 1 2 4 -1 6 -1 -1 -1 3 -1 5 7 9 -1 -1 10 11 -1 -1 -1 8 -1 -1