//
// Created by arjun on 3/15/18.
//

#ifndef BINARYSEARCHTREETRAVERSAL_BST_H
#define BINARYSEARCHTREETRAVERSAL_BST_H

#endif //BINARYSEARCHTREETRAVERSAL_BST_H


//
// Created by arjun on 3/14/18.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cstdio>

#ifndef BINARYSEARCHTREE_BST_H
#define BINARYSEARCHTREE_BST_H

#endif //BINARYSEARCHTREE_BST_H

#define COUNT 10


typedef struct BST{

    int data;
    struct BST* left;
    struct BST* right;

} BST;



BST* newNode(int n){

    BST* temp = (BST*) malloc(sizeof(BST*));

    temp->data = n;
    temp->left = NULL;
    temp->right = NULL;

    return temp;

}

BST* insert(BST* root, int n){

    if (root == NULL) {

        root = newNode(n);

    } else if (n <= root->data){

        root->left = insert(root->left, n);

    } else {

        root->right = insert(root->right, n);
    }

    return root;

}

bool search(BST* root, int n){

    if (root == NULL)
        return false;

    else if (root->data == n)
        return true;

    else if (n <= root->data )
        return search(root->left, n);

    else
        return search(root->right, n);

}

int min(BST* root){

    if (root == NULL)
        return -1;

    else if (root->left == NULL)
        return root->data;

    return min(root->left);
}

int max(BST* root){

    if (root == NULL)
        return  -1;

    else if (root->right == NULL)
        return root->data;

    return max(root->right);
}

int MAX(int a, int b){

    return (a > b) ? a : b;
}

int height(BST* root){

    if (root == NULL)
        return -1;

    else
        return MAX(height(root->left), height(root->right) + 1);
}

void printUtil(BST *root, int space){

    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    printUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Process left child
    printUtil(root->left, space);
}

void print(BST *root){

    // Pass initial space count as 0
    printUtil(root, 0);
}


bool isBinarySearchTreeUtil(BST* root, int min, int max){

    if (root == NULL)
        return true;

    if (root->data > min && root->data < max && isBinarySearchTreeUtil(root->left, min, root->data) && isBinarySearchTreeUtil(root->right, root->data, max))
        return true;

    else
        return false;
}



BST* findMinRight(BST* root){

    while(root->left != NULL)
        root = root->left;

    return root;
}

BST* findMaxLeft(BST* root){

    while(root->right != NULL)
        root = root->right;

    return root;
}


BST* Delete(BST* root, int n){

    if (root == NULL)
        return root;

    else if (n < root->data)
        root->left = Delete(root->left, n);

    else if (n > root->data)
        root->right = Delete(root->right, n);

    else {



        // Case 1: no child

        if (root->left == NULL && root->right == NULL){

            free(root);
            root = NULL;

        }

        //Case 2: One child

        else if (root->left == NULL){

            BST* temp = root;
            root = root->right;
            free(temp);

        } else if (root->right == NULL){

            BST* temp = root;
            root = root->left;
            free(temp);

        }

        // case 3: 2 children

        else {


            /*Find min in right
             * copy the value in targeted node
             * delete duplicate node from right subtree
             * */

            /*BST* temp = findMinRight(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);*/


            /*Find max in left
            * copy the value in targeted node
            * delete duplicate node from left subtree
            * */

            BST* temp = findMaxLeft(root->left);
            root->data = temp->data;
            root->left = Delete(root->left, temp->data);

        }


    }

    return root;

}

BST* find(BST* root, int data){

    if (root == NULL)
        return NULL;

    else if (root->data == data)
        return root;

    else if (data <= root->data)
        return find(root->left, data);

    else
        return find(root->right, data);
}

BST* getInorderSuccessor(BST* root, int data){

    BST* current = find(root, data);

    if (current == NULL)
        return NULL;

    if (current->right != NULL)
        return findMinRight(current->right);

    else{

        BST* successor = NULL;
        BST* ancestor = root;

        while (ancestor != current){

            if (current->data < ancestor->data){

                successor = ancestor;
                ancestor = ancestor->left;

            } else

                ancestor = ancestor->right;
        }

        return successor;
    }
}


