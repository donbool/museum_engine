#include <iostream>
#include <string>
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

        string id;
		string title;
		string culture;
		int objectYear;
        string country;
		string link;

        Node() {
            left = nullptr;
            right = nullptr;
            parent = nullptr;
            id = "";
            title = "";
            culture = "";
            objectYear = 0;
            link = "";
        }

        Node(string id, string title, string culture, int objectYear, string link) {
            left = nullptr;
            right = nullptr;
            this->id = id;
            this->title = title;
            this->culture = culture;
            this->objectYear = objectYear;
            this->country = country;
            this->link = link;
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
        void insert(Node* noder);

        void searchID(Node* root, string id, vector <string>& ids);
        void searchTitle(Node* root, string title, vector <string>& titles);
        void searchLink(Node* root, string link, vector <string>& links);

        RedBlackTree();
        RedBlackTree(Node* node);

};

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
        /*  Case : A
            Parent of pt is left child
            of Grand-parent of pt */
        if (parent_pt == grand_parent_pt->left) {
            Node *uncle_pt = grand_parent_pt->right;
            /* Case : 1
               The uncle of pt is also red
               Only Recoloring required */
            if (uncle_pt != NULL && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else {
                /* Case : 2
                   pt is right child of its parent
                   Left-rotation required */
                if (pt == parent_pt->right) {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                /* Case : 3
                   pt is left child of its parent
                   Right-rotation required */
                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color,
                           grand_parent_pt->color);
                pt = parent_pt;
            }
        }
        /* Case : B
           Parent of pt is right child
           of Grand-parent of pt */
        else {
            Node *uncle_pt = grand_parent_pt->left;
            /*  Case : 1
                The uncle of pt is also red
                Only Recoloring required */
            if ((uncle_pt != NULL) && (uncle_pt->color == RED)) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                /* Case : 2
                   pt is left child of its parent
                   Right-rotation required */
                if (pt == parent_pt->left) {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
 
                /* Case : 3
                   pt is right child of its parent
                   Left-rotation required */
                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color,grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }
    root->color = BLACK;
}

/**** insert each of the rows (artwork nodes) from the csv ****/
Node* RedBlackTree::insertNodeBSTstyle(Node* node, string id, string title, string culture, int objectYear, string link) {

    if (node == nullptr) {
        return new Node(id, title, culture, objectYear, link);
    }
    else if (id == node->id) {
    }
    else if (id < node->id) {
        node->left = insertNodeBSTstyle(node->left, id, title, culture, objectYear, link);
    }
    else {
        node->right = insertNodeBSTstyle(node->right, id, title, culture, objectYear, link);
    }
    return node;
}

void RedBlackTree::insert(Node* noder) {
    Node* pt = new Node(noder->id, noder->title, noder->culture, noder->objectYear, noder->link);
    // Do a normal BST insert
    root = insertNodeBSTstyle(root, pt->id, pt->title, pt->culture, pt->objectYear, pt->link);
 
    // fix Red Black Tree violations
    fixViolation(root, pt);
}

/****** search for the 3 different values below ******/
void RedBlackTree::searchID(Node* root, string id, vector <string>& ids) { //return anything that matches

    if (root != nullptr) {
        if (root->id == id) {
            ids.push_back(root->id);
        }
        searchID(root->left, id, ids);
        searchID(root->right, id, ids);
    }
    /*vector <long> ids;
    sprout.searchName(sprout.returnRoot(), name, ids);
    if (ids.empty()) {
                    cout << "unsuccessful" << endl;
                }
                else {
                    for (int k = 0; k < ids.size(); k++){
                        cout << to_string(ids[k]) << endl;
                    }
                }
    */
}

void RedBlackTree::searchTitle(Node* root, string title, vector <string>& titles) { //return anything that matches

    if (root != nullptr) {
        if (root->title == title) {
            titles.push_back(root->title);
        }
        searchTitle(root->left, title, titles);
        searchTitle(root->right, title, titles);
    }
    /*vector <long> titles;
    sprout.searchName(sprout.returnRoot(), name, titles);
    if (titles.empty()) {
                    cout << "unsuccessful" << endl;
                }
                else {
                    for (int k = 0; k < titles.size(); k++){
                        cout << titles(ids[k]) << endl;
                    }
                }
    */
}

void RedBlackTree::searchLink(Node* root, string link, vector <string>& links) { //return anything that matches

    if (root != nullptr) {
        if (root->link == link) {
            links.push_back(root->link);
        }
        searchLink(root->left, link, links);
        searchLink(root->right, link, links);
    }

    //for main:
    /*vector <long> links;
    sprout.searchName(sprout.returnRoot(), name, links);
    if (links.empty()) {
                    cout << "unsuccessful" << endl;
                }
                else {
                    for (int k = 0; k < links.size(); k++){
                        cout << links(ids[k]) << endl;
                    }
                }
    */
}