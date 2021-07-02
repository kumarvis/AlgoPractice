#ifndef POSTORDER_ITR_HPP
#define POSTORDER_ITR_HPP

#include<iostream>
#include<stack>
#include <unordered_set>
#include "CreateBST.hpp"

using namespace std;

void postorderIterative(struct Node *root){
    stack<struct Node*> node_stk;
    unordered_set <struct Node *> node_set ;
	struct Node* curr = root;

    while(true){
        while(curr){
            node_stk.push(curr);
            curr = curr->left;
        }
        if(node_stk.empty())
            break;

        curr = node_stk.top();

        if(node_set.find(curr) == node_set.end()){
            node_set.insert(curr);
        }else{
            cout<<curr->data<<"\t";
            //node_set.erase(curr);
            node_stk.pop();
            
        }
        curr = curr->right ;
    }

}

void run_postorderIterative() {
	vector<int> vec_arr = { 30, 20, 40, 15, 25, 35, 45 };
	struct Node* root = NULL;
	for (auto& it : vec_arr) {
		root = insertNode(root, it);
	}

    printPostOrder(root);
	cout << endl;

    postorderIterative(root);
}

#endif 