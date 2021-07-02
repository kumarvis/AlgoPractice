#ifndef FIND_ELEMENT
#define FIND_ELEMENT

#include<iostream>
#include<stack>
#include<limits>
#include "CreateBST.hpp"
using namespace std;

bool findElementBinaryTree(struct Node *root, int val) {
    if(root==NULL)
    return false ;

    return ((root->data == val) || findElementBinaryTree(root->left, val) ||
        findElementBinaryTree(root->right, val));

}

void run_findElementBinaryTree() {
	vector<int> vec_arr = { 30, 20, 40, 15, 25, 35, 45 };
	struct Node* root = NULL;

	for (auto& it : vec_arr) {
		root = insertNode(root, it);
	}

	printInorder(root);
	cout << endl;
    vector<int> vec_val = {27, 45, 50};
    for (auto item : vec_val){
        int ans = findElementBinaryTree(root, item);
        cout<<"Element "<<item<<" "<<ans<<endl;
    }

}

#endif 
