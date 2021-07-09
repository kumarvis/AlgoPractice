#ifndef IS_BST
#define IS_BST

//#include<iostream.h>

#include<iostream>
#include<stack>
#include <limits>
#include<string>

#include "CreateBST.hpp"

bool isBSTWrong(struct Node *root){
    if(root==NULL)
        return true ; 
    bool is_bst = true;
    if(root->left != NULL && (root->data < root->left->data))
        is_bst = false ;
    if(root->right != NULL && (root->data > root->right->data))
        is_bst = false ;
    
    return is_bst && isBSTWrong(root->left) && isBSTWrong(root->right);
}

void run_isBST(){
    vector<int> vec_arr = {30, 20, 40, 15, 25, 35, 45, 10, 17, 18};
	struct Node* root = NULL;
	for (auto& it : vec_arr) {
		root = insertNode(root, it);
	}
	printInorder(root);
    bool ans = isBSTWrong(root);
    cout<<"IS BST = "<<ans<<endl;
}

#endif 