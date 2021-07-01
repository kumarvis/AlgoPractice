#ifndef SAME_STRUCT_TREE
#define SAME_STRUCT_TREE

#include<iostream>
#include<stack>
#include <limits>
#include "CreateBST.hpp"

bool checkStructBtree(struct Node* root1, struct Node* root2) {
	if (root1 == NULL && root2 == NULL)
		return true;
	if (root1 != NULL && root2 != NULL) {
		bool l = checkStructBtree(root1->left, root2->left);
		bool r = checkStructBtree(root1->right, root2->right);
		bool ans = l & r;
		return ans;
	}else {
		return false;
	}
}

void run_checkStructBtree() {
	vector<int> vec_arr1 = {30, 20, 40, 15, 25, 35, 45 };
	struct Node* root1 = NULL;

	for (auto& it : vec_arr1) {
		root1 = insertNode(root1, it);
	}
	printInorder(root1);

	vector<int> vec_arr2 = { 300, 200, 400, 150, 250, 350, 450, 500};
	struct Node* root2 = NULL;

	for (auto& it : vec_arr2) {
		root2 = insertNode(root2, it);
	}
	printInorder(root2);

	bool ans = checkStructBtree1(root1, root2);
	cout << "Tree is " << ans << endl;
	cout << endl;
}
#endif 
