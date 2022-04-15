#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Values: 
			Object Number, Object Name, Title,
			Culture, Object Year (avg), Link Resource
*/

class Node {
    public:
        Node* left;
        Node* right;

        string id;
		string objectName;
		string title;
		string culture;
		int objectYear;
		string link;

        Node() {
            left = nullptr;
            right = nullptr;
            id = "";
            objectName = "";
            title = "";
            culture = "";
            objectYear = 0;
            link = "";
        }

        Node(string id, string objectName, string title, string culture, int objectYear, string link) {
            left = nullptr;
            right = nullptr;
            this->id = id;
            this->objectName = objectName;
            this->title = title;
            this->culture = culture;
            this->objectYear = objectYear;
            this->link = link;
        }
};

class BST {
    private:
        Node* head = nullptr;

    public:
        Node* insertNode(Node* node, string id, string objectName, string title, string culture, int objectYear, string link);
        
        void searchID(Node* root, string id, vector <string>& ids);
        void searchTitle(Node* root, string title, vector <string>& ids);
        void searchLink(Node* root, string link, vector <string>& ids);

        Node* returnRoot();
        void setRoot(Node* node);

        BST();
        BST(Node* node);
};

/**** insert each of the rows (artwork nodes) from the csv ****/
Node* BST::insertNode(Node* node, string id, string objectName, string title, string culture, int objectYear, string link) {

    if (node == nullptr) {
        return new Node(id, objectName, title, culture, objectYear, link);
    }
    else if (id == node->id) {
    }
    else if (id < node->id) {
        node->left = insertNode(node->left, id, objectName, title, culture, objectYear, link);
    }
    else {
        node->right = insertNode(node->right, id, objectName, title, culture, objectYear, link);
    }
    return node;
}

/****** search for the 3 different values below ******/
void BST::searchID(Node* root, string id, vector <string>& ids) { //return anything that matches

    if (root != nullptr) {
        if (root->id == id) {
            ids.push_back(root->id);
        }
        searchID(root->left, id, ids);
        searchID(root->right, id, ids);
    }
}

void BST::searchTitle(Node* root, string title, vector <string>& ids) { //return anything that matches

    if (root != nullptr) {
        if (root->title == title) {
            ids.push_back(root->id);
        }
        searchTitle(root->left, title, ids);
        searchTitle(root->right, title, ids);
    }
}

void BST::searchLink(Node* root, string link, vector <string>& ids) { //return anything that matches

    if (root != nullptr) {
        if (root->link == link) {
            ids.push_back(root->id);
        }
        searchLink(root->left, link, ids);
        searchLink(root->right, link, ids);
    }
}