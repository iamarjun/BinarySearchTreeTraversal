#include <iostream>
#include <queue>
#include <climits>
#include "BST.h"

using namespace std;


void levelOrderTraversal(BST* root){

    if (root == NULL)
        return;

    queue<BST*> q;

    q.push(root);

    while (!q.empty()){

        BST* current = q.front();
        cout<<current->data<<" ";
        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);

        q.pop();
    }
}

void preorderTraversal(BST* root){

    //root->left->right

    if (root == NULL)
        return;

    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(BST* root){

    //left->root->right

    if (root == NULL)
        return;

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}



void postorderTraversal(BST* root){

    //left->right->root

    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

bool isBinarySearchTree(BST* root){

    if (isBinarySearchTreeUtil(root, INT_MIN, INT_MAX))
        return true;

    else
        return false;
}



int main() {

    BST* root = NULL;

    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 25);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, 17);
    root = insert(root, 16);
    root = insert(root, 25);
    root = insert(root, 27);

    print(root);
    cout<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    preorderTraversal(root);
    cout<<endl;
    inorderTraversal(root);
    cout<<endl;
    postorderTraversal(root);
    cout<<endl;
    Delete(root, 10);
    print(root);


    return 0;
}


