#ifndef LCA
#define LCA

#include<iostream>
#include<stack>
#include<limits>
#include "CreateBST.hpp"
using namespace std;

bool getPathFromRoot(struct Node *root, int elm, vector<int> &vec_path){
    if(root == NULL)
        return false ;
    
    vec_path.push_back(root->data);
    if(root->data == elm){
        return true ;
    }

    bool l = getPathFromRoot(root->left, elm, vec_path);
    if(!l){
        bool r =  getPathFromRoot(root->right, elm, vec_path);
        if(!r)
            vec_path.pop_back();
        return r ;
    }else 
        return l ;
}

void printVector(vector<int> vec_arr){
    for(auto item: vec_arr)
        cout<<item<<'\t';
    cout<<endl;
}

int getLCAElement(struct Node *root, int elm1, int elm2){
    vector<int> vec_elm1, vec_elm2;
    getPathFromRoot(root, elm1, vec_elm1);
    printVector(vec_elm1);
    getPathFromRoot(root, elm2, vec_elm2);
    printVector(vec_elm2);
}

void run_LCA(){
    vector<int> vec_arr = { 30, 20, 40, 15, 25, 35, 45 };
	struct Node* root = NULL;

	for (auto& it : vec_arr) {
		root = insertNode(root, it);
	}

	printInorder(root);
	cout << endl;
    int ans = getLCAElement(root, 15, 45);

}

#endif 