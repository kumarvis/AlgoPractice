#ifndef DIAMETER_BINARY
#define DIAMETER_BINARY

#include<iostream>
#include<stack>
#include<limits>
#include "CreateBST.hpp"
#include <math.h>

using namespace std;

int getHeight(struct Node *root){
    if(root==NULL)
        return 0;
    int l = getHeight(root->left);
    int r = getHeight(root->right);
    int ans = max(l, r) + 1;
    return ans ;
}

int getDiameterBinary(struct Node *root){
    if(root==NULL)
        return 0;
    int l = getDiameterBinary(root->left);
    int r = getDiameterBinary(root->right);
    int ht_l = getHeight(root->left);
    int ht_r = getHeight(root->right);
    int ans = max(max(l, r), ht_l + ht_r + 1);
    return ans ;
}

void run_getDiameterBinary(){
    vector<int> vec_arr = {30, 20, 40, 15, 25, 35, 45};
	struct Node* root = NULL;

	for (auto& it : vec_arr) {
		root = insertNode(root, it);
	}

	printInorder(root);
	cout << endl;
    int ans = getDiameterBinary(root);
    cout<<"Diameter of inary Tree = "<<ans <<endl;
}

#endif 

