#ifndef FIND_MAX
#define FIND_MAX

#include<iostream>
#include<stack>
#include "CreateBST.hpp"
using namespace std;

int findMaxBtree(struct Node* root) {
	
	if (root == NULL)
		return INT_MIN;
	int res = root->data;
	int l = findMaxBtree(root->left);
	int r = findMaxBtree(root->right);
	l = (l > r) ? l : r;
	res = (res > l) ? res : r;
	return res;
}

void run_findMaxBtree() {
	vector<int> vec_arr = { 30, 20, 40, 15, 25, 35, 45 };
	struct Node* root = NULL;

	for (auto& it : vec_arr) {
		root = insertNode(root, it);
	}

	printInorder(root);
	cout << endl;
	int ans = findMaxBtree(root);
	cout << "Max Element Binary Tree = " << ans << endl;

}

#endif 
