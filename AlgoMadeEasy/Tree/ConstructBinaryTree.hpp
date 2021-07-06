#ifndef CONSTRUCT_BINARYTREE_HPP
#define CONSTRUCT_BINARYTREE_HPP

#include<iostream>
#include <stack>
#include <limits>
#include<vector>
#include "CreateBST.hpp"

int getInorderIndex(vector<int> vec_in, int data) {
	vector<int>::iterator it = find(vec_in.begin(), vec_in.end(), data);
	int index = it - vec_in.begin();
	return index;
}

struct Node* constructBinaryTree(vector<int> vec_in, int st_index, int end_index, 
	vector<int> vec_pre, int &pre_order_index) {
	if (st_index > end_index)
		return NULL; 
	int node_val = vec_pre[pre_order_index++];
	int inorder_index = getInorderIndex(vec_in, node_val);
	struct Node* root = new Node();
	root->data = node_val;
	root->left = constructBinaryTree(vec_in, st_index, inorder_index - 1, vec_pre, pre_order_index);
	root->right = constructBinaryTree(vec_in, inorder_index + 1, end_index, vec_pre, pre_order_index);
	
	return root;


}

void run_constructBinaryTree() {
	vector<int> vec_inorder = {9, 3, 15, 20, 7};
	vector<int> vec_preorder = {3, 9, 20, 15, 7};
	struct Node* root = NULL; 
	int st_index = 0; 
	int end_index = vec_inorder.size() - 1;
	int pre_index = 0;
	root = constructBinaryTree(vec_inorder, st_index, end_index, vec_preorder, pre_index);
	printInorder(root);
}

#endif 
