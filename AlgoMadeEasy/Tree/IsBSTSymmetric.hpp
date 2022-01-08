#ifndef IS_BST_SYMM
#define IS_BST_SYMM

#include<iostream>
#include<stack>
#include <limits>
#include<string>
#include "CreateBST.hpp"

void isBSTSymmetric(){
    
}

void run_isBSTSymmetric(){
    //vector<int> vec_arr = {30, 20, 40, 15, 25, 35, 45, 10, 17, 18};
    vector<int> vec_arr = {10, 4, 1, 6, 12, 13, 14};
	struct Node* root = NULL;
	for (auto& it : vec_arr) {
		root = insertNode(root, it);
	}
	printInorder(root);
    bool ans = true;
    cout<<endl;
    isBSTSymmetric(root, ans);
    cout<<"BST is Balance Tree = "<<ans<<endl;
}


#endif 