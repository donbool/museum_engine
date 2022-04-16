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

        Node(string id, string objectName, string title, string culture, int objectYear, string link) {
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
        Node* insertNodeBSTstyle(Node* node, string id, string objectName, string title, string culture, int objectYear, string link);
        void rotateLeft(Node *&, Node *&);
        void rotateRight(Node *&, Node *&);
        void fixViolation(Node *&, Node *&);
        void RedBlackTree::insert(const int &data);

        void searchID(Node* root, string id, vector <string>& ids);
        void searchTitle(Node* root, string title, vector <string>& ids);
        void searchLink(Node* root, string link, vector <string>& ids);

        RedBlackTree();
        RedBlackTree(Node* node);
};

/**** insert each of the rows (artwork nodes) from the csv ****/
Node* RedBlackTree::insertNodeBSTstyle(Node* node, string id, string objectName, string title, string culture, int objectYear, string link) {

    if (node == nullptr) {
        return new Node(id, objectName, title, culture, objectYear, link);
    }
    else if (id == node->id) {
    }
    else if (id < node->id) {
        node->left = insertNodeBSTstyle(node->left, id, objectName, title, culture, objectYear, link);
    }
    else {
        node->right = insertNodeBSTstyle(node->right, id, objectName, title, culture, objectYear, link);
    }
    return node;
}

void RedBlackTree::insert(const int &data) {
    Node *pt = new Node(data);
 
    // Do a normal BST insert
    root = insertNodeBSTstyle(root, pt);
 
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
}

void RedBlackTree::searchTitle(Node* root, string title, vector <string>& ids) { //return anything that matches

    if (root != nullptr) {
        if (root->title == title) {
            ids.push_back(root->id);
        }
        searchTitle(root->left, title, ids);
        searchTitle(root->right, title, ids);
    }
}

void RedBlackTree::searchLink(Node* root, string link, vector <string>& ids) { //return anything that matches

    if (root != nullptr) {
        if (root->link == link) {
            ids.push_back(root->id);
        }
        searchLink(root->left, link, ids);
        searchLink(root->right, link, ids);
    }
}