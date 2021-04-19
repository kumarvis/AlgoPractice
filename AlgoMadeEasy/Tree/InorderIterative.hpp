#ifndef INORDER_ITR_HPP
#define INORDER_ITR_HPP

#include<iostream>
#include<stack>
#include "CreateBST.hpp"

using namespace std;

void inorderIterative(struct Node *root) {
	stack<struct Node*> node_stk;
	struct Node* tmp = root;
	
	do {
		node_stk.push(tmp);
		tmp = tmp->left;
	} while (tmp);
			
	struct Node* curr = node_stk.top();
	cout << curr->data << "\t";
	tmp = curr->right;
	node_stk.pop();

}

void run_inorderIterative() {
	vector<int> vec_arr = { 35, 20, 40, 15, 25, 35, 45 };
	struct Node* root = NULL;
	for (auto& it : vec_arr) {
		root = insertNode(root, it);
	}

	printInorder(root);
	cout << endl;
	inorderIterative(root);
	cout << endl;
	

}

#endif // !INORDER_ITR_HPP
