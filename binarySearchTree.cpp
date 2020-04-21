#include <iostream>
#include <vector>
#include <queue>
#include <climits>

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

TreeNode* builtBST(TreeNode* root, int data) {
	if (root == NULL) {
		return new TreeNode(data);
		// root = new TreeNode(data);
		// return root;
	}

	if (root->val > data) {
		root->left = builtBST(root->left, data);
	} else {
		root->right = builtBST(root->right, data);
	}

	return root;
}

TreeNode* insert() {

	TreeNode* root = NULL;

	int data;
	cin >> data;

	while (data != -1) {
		root = builtBST(root, data);
		cin >> data;
	}

	return root;
}

void inOrder(TreeNode* root) {
	if (root == NULL) return;

	inOrder(root->left);
	cout << root->val << " ";
	inOrder(root->right);
}

bool searchBST(TreeNode* root, int key){

	if(root == NULL){
		return false;
	}

	if(root->val == key){
		return true;
	}

	if(key > root->val){
		return searchBST(root->right,key);
	}
	else{
		return searchBST(root->left,key);
	}
}
    
TreeNode* helper(vector<int>& nums,int start,int end){
    
    if(start > end){
        return NULL;
    }
    
    int mid = (start + end)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = helper(nums,start,mid-1);
    root->right = helper(nums,mid+1,end);
    
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums,0,nums.size()-1);
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

int kthSmallest(TreeNode* root, int k) {
    int ans;
    inOrderTraversal(root,k,ans);
    
    return ans;
}

class TreeDetail{
public:
	bool bst;
	int size;
	int maxVal;
	int minVal;
};

TreeDetail largestBstInBinaryTree(TreeNode* root){
	TreeDetail obj;

	if(root == NULL){
		obj.bst = true;
		obj.size = 0;
		obj.minVal = INT_MAX;
		obj.maxVal = INT_MIN;
		return obj;
	}

	TreeDetail leftStatus = largestBstInBinaryTree(root->left);
	TreeDetail rightStatus = largestBstInBinaryTree(root->right);

	if(!leftStatus.bst or !rightStatus.bst or root->val < leftStatus.maxVal or root->val > rightStatus.minVal){
		obj.bst = false;
		obj.size = max(leftStatus.size,rightStatus.size);
		return obj;
	}

	obj.bst = true;
	obj.size = leftStatus.size + rightStatus.size + 1;
	obj.maxVal = root->right != NULL ? rightStatus.maxVal : root->val;
	obj.minVal = root->left != NULL ? leftStatus.minVal : root->val;

	return obj;
}

int main(){
	// TreeNode* root = insert();

	// inOrder(root);
	// cout<<endl;

	TreeNode* root = NULL;
	root = builtTree(root);

	// cout<<searchBST(root,5)<<endl;
	// cout<<searchBST(root,21)<<endl;

	// vector<int> nums = {1,2,3,4,5,6,7};
	// int n = nums.size();
	// vector<int> left (nums.begin() + n/2 + 1,nums.end());

	// for(int i=0;i<left.size();i++){
	// 	cout<<left[i]<<" ";
	// }
	// cout<<endl;

	TreeDetail obj = largestBstInBinaryTree(root);
	cout<<obj.size<<endl;


}


// 4 2 1 3 6 5 7 -1

// 8 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1 9 7 -1 -1 10 -1 -1