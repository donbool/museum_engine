#include "splay.h"

Node* Splay::getRoot(){return root;}
Splay::Splay(){
	root = nullptr;
}
//both left and right rotations are inspired from geeks4geeks(https://www.geeksforgeeks.org/splay-tree-set-2-insert-delete/?ref=lbp) splay tree as well as github: //this bit of insertion code was inspired by a github repository: https://github.com/Bibeknam/algorithmtutorprograms/blob/master/data-structures/splay-trees/SplayTree.cpp
void Splay::rightRotate(Node *x){
        Node* y = x->left;
        x->left = y->right;
        if (y->right != nullptr) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
}
void Splay::leftRotate(Node* x){
    Node* y = x->left;
    x->left = y->right;
    if (y->right != nullptr) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        this->root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
        y->right = x;
        x->parent = y;
    }
//this bit of insertion code was inspired by a github repository: https://github.com/Bibeknam/algorithmtutorprograms/blob/master/data-structures/splay-trees/SplayTree.cpp
void Splay::splayHelper(Node *root) {
    while (root->parent && !root) {
        if (!root->parent->parent) {
            //simply single rotations
            if (root == root->parent->left) {
                rightRotate(root->parent);
            } else {
                leftRotate(root->parent);
            }
        } else if (root == root->parent->left && root->parent == root->parent->parent->left) {
            //RR rotation
            rightRotate(root->parent->parent);
            rightRotate(root->parent);
        } else if (root == root->parent->right && root->parent == root->parent->parent->right) {
            //LL Rotation
            leftRotate(root->parent->parent);
            leftRotate(root->parent);
        } else if (root == root->parent->right && root->parent == root->parent->parent->left) {
            //LR Rotation
            leftRotate(root->parent);
            rightRotate(root->parent);
        } else {
            //RL rotation
            rightRotate(root->parent);
            leftRotate(root->parent);
            }
        }
}
//this bit of insertion code was inspired by a github repository: https://github.com/Bibeknam/algorithmtutorprograms/blob/master/data-structures/splay-trees/SplayTree.cpp
void Splay::insertHelper(ArtWork piece){
    // normal BST insert
    Node* node = new Node(piece);
    node->parent = nullptr;
    node->left = nullptr;
    node->right = nullptr;

    Node* y = nullptr;
    Node* x = this->root;

    while (x != nullptr){
        y = x;
        if(node->work.getID() < x->work.getID()) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    node->parent = y;
    if(y == nullptr){
        root = node;
    }
    else if(node->work.getID() < y->work.getID()){
        y->left = node;
    }
    else{
        y->right = node;
    }

    // splay the node
    splayHelper(node);
}
//this search recursion method helps the main search function
Node* Splay::searchHelper(Node* root, string id){
    if(root == nullptr || root->work.getID().compare(id) == 0){
        return root;
    }

    if(id < root->work.getID())
        return searchHelper(root->left, id);
    else
        return searchHelper(root->right, id);
}
//this function helps find the correct art piece and splay it to the top
Node* Splay::search(string id){
    Node* found = searchHelper(this->root,id);
    if(found == nullptr)
        return found;
    else{
        splayHelper(found);
        return found;
    }
}

