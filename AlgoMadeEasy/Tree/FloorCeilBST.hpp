#ifndef FLOOR_CEIL_BST
#define FLOOR_CEIL_BST

#include <iostream>
#include <stack>
#include <limits>
#include <string>
#include "CreateBST.hpp"


void ceilBST(struct Node *root, int key, int & ans){
    if(root==NULL)
        return ;
    ceilBST(root->right, key, ans);
    if(root->data >= key){
        ans = root->data;
    }else {
        return;
    }
    ceilBST(root->left, key, ans);
}

void floorBST(struct Node *root, int key, int & ans){
    if(root==NULL)
        return;

    floorBST(root->left, key, ans);
    if(root->data <= key){
        ans = root->data;
    }else{
        return ;
    }
    floorBST(root->right, key, ans);
}   

void run_floorceilBST() {
    vector<int> vec_arr = {30, 20, 40, 15, 25, 35, 45, 10, 17, 18};
	struct Node* root = NULL;
	for (auto& it : vec_arr) {
		root = insertNode(root, it);
	}
	printInorder(root);
    cout<<endl;
    printReverseInorder(root);
    int key = 16 ;
    int ans = -1;
    floorBST(root, key, ans);
    cout<<endl;
    cout<<" Floor of = "<<key<<" is = "<<ans<<endl;
    ceilBST(root, key, ans);
    cout<<endl;
    cout<<"Ceil of = "<<key<<" is = "<<ans<<endl;
}

#endif 