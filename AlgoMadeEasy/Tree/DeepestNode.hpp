#ifndef DEEPEST_ELM
#define DEEPEST_ELM

#include<iostream>
#include<stack>
#include <limits>
#include "CreateBST.hpp"

void getSingleDeepestElement(struct Node *root, int level, int &maxlevel, int &ans) {
	if (root) {
		getSingleDeepestElement(root->left, level + 1, maxlevel, ans);
		if (level > maxlevel) {
			ans = root->data;
			maxlevel = level;
		}
		getSingleDeepestElement(root->right, level + 1, maxlevel, ans);	
	}
}

int getBinaryTreeHt(struct Node *root) {
	if (root == NULL)
		return 0; 
	int l = getBinaryTreeHt(root->left);
	int r = getBinaryTreeHt(root->right);
	int ans = (l > r) ? l : r;
	return ans + 1;
}
void getDeepestElements(struct Node *root, int ht, int level, vector<int> &vec_arr) {
	if (root) {
		getDeepestElements(root->left, ht, level+1, vec_arr);
		if (level == ht) {
			vec_arr.push_back(root->data);
		}
		getDeepestElements(root->right, ht, level + 1, vec_arr);
	}
}

void run_OneDeepestElement() {
	vector<int> vec_arr = { 30, 20, 40, 15, 25, 35, 45};
	struct Node* root = NULL;

	for (auto& it : vec_arr) {
		root = insertNode(root, it);
	}
	printInorder(root);

	cout << endl;
	vector<int> vec_val = { 30, 20, 40, 50, 18 };
	int level = 1;
	int max_level = numeric_limits<int>::min();
	int ans = 0;
	//getSingleDeepestElement(root, level, max_level, ans);
	//cout << "Deepest Element = " << ans << endl;
	int ht = getBinaryTreeHt(root);
	vector<int> vec_deep_elm;
	
	getDeepestElements(root, ht, 1, vec_deep_elm);
	cout << "Deepest Elements = " << endl;
	for (auto item : vec_deep_elm)
		cout << item << " ";
	
	cout << endl;
}

#endif 
