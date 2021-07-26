#ifndef IS_BST
#define IS_BST

//#include<iostream.h>

#include<iostream>
#include<stack>
#include <limits>
#include<string>
#include "CreateBST.hpp"

void isBSTCorrect(struct Node *root, bool & ans){
    static struct Node *prev = NULL ;
    if(root==NULL)
        return;

    isBSTCorrect(root->left, ans);
    if(prev != NULL ){
        ans = (prev->data < root->data);
        if(!ans)
            return ;
    }
    prev = root ; 
    isBSTCorrect(root->right, ans);
    
}

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
    //vector<int> vec_arr = {30, 20, 40, 15, 25, 35, 45, 10, 17, 18};
    vector<int> vec_arr = {10, 4, 1, 6, 12 };
	struct Node* root = NULL;
	for (auto& it : vec_arr) {
		root = insertNode(root, it);
	}
    root->right->data = 3;
	printInorder(root);
    bool ans = true ; 
    cout<<endl;
    isBSTCorrect(root, ans);
    cout<<"IS BST = "<<ans<<endl;
}

#endif 