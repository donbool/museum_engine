#include <iostream>
#include "artwork.cpp"
#include <string>
#include <vector>

using namespace std;

/* Values: 
			Object Number, Title,
			Culture, Object Year (avg), Link Resource
*/

enum Color {RED, BLACK};

class Node {
    public:
        Node* left;
        Node* right;
        Node* parent;

        bool color;

        ArtWork work;

        Node() {
            left = nullptr;
            right = nullptr;
            parent = nullptr;
            work = ArtWork();
        }

        Node(ArtWork piece){
            left = nullptr;
            right = nullptr;
            parent = nullptr;
            work = piece;
        }
};

class RedBlackTree {
    private:
        Node* root = nullptr;

    public:
        Node* insertNodeBSTstyle(Node* node, string id, string title, string culture, int objectYear, string link);
        void rotateLeft(Node *&root, Node *&pt);
        void rotateRight(Node *&root, Node *&pt);
        void fixViolation(Node *&root, Node *&pt);
        void insert(ArtWork piece);

        void searchID(Node* root, string id, vector <string>& ids);
        void searchTitle(Node* root, string title, vector <string>& titles);
        void searchLink(Node* root, string link, vector <string>& links);

        RedBlackTree();
        RedBlackTree(Node* node);

};

RedBlackTree::RedBlackTree() {
    root = nullptr;
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

Node* RedBlackTree::insertNodeBSTstyle(Node* node, string id, string title, string culture, int objectYear, string link) {

    if (node == nullptr) {
        return new Node();
    }
    else if (id == node->work.getID()) {
    }
    else if (id < node->work.getID()) {
        node->left = insertNodeBSTstyle(node->left, id, title, culture, objectYear, link);
    }
    else {
        node->right = insertNodeBSTstyle(node->right, id, title, culture, objectYear, link);
    }
    return node;
}

void RedBlackTree::insert(ArtWork piece) {
    Node* pt = new Node(piece);
    root = insertNodeBSTstyle(root, piece.getID(), piece.getTitle(), piece.getCulture(), piece.getObjectYear(), piece.getLink());
    fixViolation(root, pt);
}

void RedBlackTree::searchID(Node* root, string id, vector <string> &ids) { //return anything that matches

    if (root != nullptr) {
        if (root->work.getID() == id) {
            ids.push_back(root->work.getID());
        }
        searchID(root->left, id, ids);
        searchID(root->right, id, ids);
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