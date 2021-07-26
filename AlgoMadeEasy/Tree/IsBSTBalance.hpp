#ifndef IS_BST_BALANCE
#define IS_BST_BALANCE

#include<iostream>
#include<stack>
#include <limits>
#include<string>
#include "CreateBST.hpp"

const int ONE = 1;

int isBSTBalance(struct Node *root, bool &bst_balance){
    if(root==NULL)
        return 0 ;
    int l = isBSTBalance(root->left, bst_balance); 
    int r = isBSTBalance(root->right, bst_balance); 
    
    if(abs(l-r) <= ONE){
        return max(l, r)+1;
    }else{
        bst_balance = false ;
        return 0;
    }
}

void run_isBSTBALANCE(){
    //vector<int> vec_arr = {30, 20, 40, 15, 25, 35, 45, 10, 17, 18};
    vector<int> vec_arr = {10, 4, 1, 6, 12, 13, 14};
	struct Node* root = NULL;
	for (auto& it : vec_arr) {
		root = insertNode(root, it);
	}
	printInorder(root);
    bool ans = true;
    cout<<endl;
    isBSTBalance(root, ans);
    cout<<"BST is Balance Tree = "<<ans<<endl;
}

#endif 