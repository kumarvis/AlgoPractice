#ifndef COMPARE_TREE
#define COMPARE_TREE

#include <iostream>
#include <stack>
#include <limits>
#include <math.h>
#include <vector>
#include "CreateBST.hpp"
using namespace std;

void getMirrorImage(struct Node *root){
    if(root){
        getMirrorImage(root->left);
        getMirrorImage(root->right);
        swap(root->left, root->right);
    }
}

bool compareNode(struct Node *root1, struct Node *root2){
    if(!root1 && !root2)
        return true;
    if(root1->data == root2->data)
        return true;
    
    return false ;
}

bool isMirrorImage(struct Node *root1, struct Node *root2){
    if(root1==NULL && root2==NULL)
        return true ;
    isMirrorImage(root1->left, root2->left);
    bool l = compareNode(root1->left, root2->left);
    isMirrorImage(root1->right, root2->right);
    bool r = compareNode(root1->left, root2->left);
    return l & r ;
}

bool isSameTree(struct Node *root1, struct Node *root2){
    if(root1==NULL && root2==NULL)
        return true ;
    
    if(root1 != NULL && root2 != NULL && root1->data == root2->data){
        bool l = isSameTree(root1->left, root2->left);
        if(l)
            return isSameTree(root1->right, root2->right);
        else
            return l;

    }else {
        return false ;
    }

}

void run_compareTree(){
    vector<int> vec_arr = {30, 20, 40, 15, 25, 35, 45};
	struct Node* root1 = NULL;
    struct Node* root2 = NULL;

	for (auto& it : vec_arr) {
		root1 = insertNode(root1, it);
        root2 = insertNode(root2, it);
	}
    printInorder(root1);
	cout << endl;
    cout<<"Print Inorder Mirror Image"<<endl;
    //getMirrorImage(root1);
    //printInorder(root1);
    bool ans = isSameTree(root1, root2);
    cout<<"isSameTree = "<<ans<<endl;
}


#endif 