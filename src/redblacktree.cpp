#include "redblacktree.h"

RedBlackTree::RedBlackTree() {
    root = nullptr;
}

Node* RedBlackTree::getRoot(){
	return root;
}

//Citation: Inspired by Geeks4Geeks
void RedBlackTree::rotateLeft(Node *&root, Node *&pt) {
    Node *pt_right = pt->right;
 
    pt->right = pt_right->left;
 
    if (pt->right != NULL)
        pt->right->parent = pt;
 
    pt_right->parent = pt->parent;
 
    if (pt->parent == NULL)
        root = pt_right;
 
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
 
    else
        pt->parent->right = pt_right;
 
    pt_right->left = pt;
    pt->parent = pt_right;
}
 
void RedBlackTree::rotateRight(Node *&root, Node *&pt) {
    Node *pt_left = pt->left;
 
    pt->left = pt_left->right;
 
    if (pt->left != NULL)
        pt->left->parent = pt;
 
    pt_left->parent = pt->parent;
 
    if (pt->parent == NULL)
        root = pt_left;
 
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
 
    else
        pt->parent->right = pt_left;
 
    pt_left->right = pt;
    pt->parent = pt_left;
}

void RedBlackTree::fixViolation(Node *&root, Node *&pt) {
    Node *parent_pt = NULL;
    Node *grand_parent_pt = NULL;
 
    while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;
        if (parent_pt == grand_parent_pt->left) {
            Node *uncle_pt = grand_parent_pt->right;
            if (uncle_pt != NULL && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else {
                if (pt == parent_pt->right) {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color,
                           grand_parent_pt->color);
                pt = parent_pt;
            }
        }
        else {
            Node *uncle_pt = grand_parent_pt->left;

            if ((uncle_pt != NULL) && (uncle_pt->color == RED)) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {

                if (pt == parent_pt->left) {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color,grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }
    root->color = BLACK;
}

Node* RedBlackTree::BSTInsertID(Node* root, Node *pt)
{
    /* If the tree is empty, return a new node */
    if (root == NULL)
       return pt;
 
    /* Otherwise, recur down the tree */
    if (pt->work.getID().compare(root->work.getID()) < 0)
    {
        root->left  = BSTInsertID(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->work.getID().compare(root->work.getID()) > 0)
    {
        root->right = BSTInsertID(root->right, pt);
        root->right->parent = root;
    }
 
    /* return the (unchanged) node pointer */
    return root;
}

void RedBlackTree::insert(ArtWork piece)
{
    Node *pt = new Node(piece);
 
    // Do a normal BST insert
    root = BSTInsertID(root, pt);
 
    // fix Red Black Tree violations
    fixViolation(root, pt);
}

void RedBlackTree::searchID(Node* root, string id, vector<ArtWork>& result) { //return anything that matches

    if (root != nullptr) {
        if (root->work.getID() == id) {
            result.push_back(root->work);
        }
        searchID(root->left, id, result);
        searchID(root->right, id, result);
    }
}

void RedBlackTree::searchTitle(Node* root, string title, vector <string>& titles) { //return anything that matches

    if (root != nullptr) {
        if (root->work.getTitle() == title) {
            titles.push_back(root->work.getTitle());
        }
        searchTitle(root->left, title, titles);
        searchTitle(root->right, title, titles);
    }
}

void RedBlackTree::searchLink(Node* root, string link, vector <string>& links) { //return anything that matches

    if (root != nullptr) {
        if (root->work.getLink() == link) {
            links.push_back(root->work.getLink());
        }
        searchLink(root->left, link, links);
        searchLink(root->right, link, links);
    }
}
