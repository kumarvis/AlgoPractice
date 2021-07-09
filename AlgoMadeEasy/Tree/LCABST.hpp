#ifndef LCA_BST
#define LCA_BST

//#include<iostream.h>

#include<iostream>
#include<stack>
#include <limits>
#include<string>

#include "CreateBST.hpp"

struct Node * getLCABST(struct Node *root, int elm1, int elm2){
    if(root==NULL)
        return NULL ;
    if(root->data >= elm1 && root->data <= elm2)
        return root;
    else{
        if(root->data < elm1 && root->data < elm2)
            return getLCABST(root->right, elm1, elm2);
        else
            return getLCABST(root->left, elm1, elm2);
    }
}

void run_LCABST() {
    vector<int> vec_arr = {30, 20, 40, 15, 25, 35, 45, 10, 17, 18};
	struct Node* root = NULL;
	for (auto& it : vec_arr) {
		root = insertNode(root, it);
	}
	printInorder(root);
    int elm1 = 30;
    int elm2 = 45; 
	struct Node * ans = getLCABST(root, elm1, elm2);
    cout<<endl;
    if(ans)
        cout<<"LCA for  = "<<elm1<<" "<<elm2<<"is = "<<ans->data<<endl;
    else
        cout<<"Element Not found";

}

#endif 