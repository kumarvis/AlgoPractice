#ifndef BST_DELETE
#define BST_DELETE

//#include<iostream.h>

#include<iostream>
#include<stack>
#include <limits>
#include<string>

#include "CreateBST.hpp"

struct Node * deleteNodeBST(struct Node *root, int data) {
	if (root->data == data) {
		if(root->left != NULL && root->right != NULL){
			struct Node *tmp = root->left ; 
			while(tmp && tmp->right)
				tmp = tmp->right;
			root->data = tmp->data;
			root->left = deleteNodeBST(root->left, tmp->data);
		}else {
			if (root->left == NULL && root->right == NULL) {
				delete root;
				return NULL; 
			}else {
				struct Node* tmp = NULL; 
				if (root->left == NULL)
					tmp = root->right;
				if (root->right == NULL)
					tmp = root->left;
				delete root; 
				return tmp;
			}		
		}
	}else {
		if (data < root->data)
			root->left = deleteNodeBST(root->left, data);
		else
			root->right = deleteNodeBST(root->right, data);
	}
}

void run_deleteNodeBST() {

	vector<int> vec_arr = {30, 20, 40, 15, 25, 35, 45, 10, 17, 18};
	struct Node* root = NULL;

	for (auto& it : vec_arr) {
		root = insertNode(root, it);
	}

	printInorder(root);
	int elm = 20; 
	deleteNodeBST(root, elm);
	cout<<endl;
	printInorder(root);
}


#endif 
