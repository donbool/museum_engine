#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Values: 
			Object Number,Object Name,Title,
			Culture,Object Year (avg),
			Country,Link Resource,
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
		string country;
		string link;

        Node() {
            left = nullptr;
            right = nullptr;
        }

        Node(string name, int id) {
            left = nullptr;
            right = nullptr;
            this->id = id;
            this->objectName = objectName;
            this->title = title;
            this->culture = culture;
            this->objectYear = objectYear;
            this->country = country;
            this->link = link;
        }
};

class BST {
    private:
        Node* head = nullptr;
        int height;
        //Right rotate
        //Left rotate   

    public:
        Node* insertNode(Node* node, int id, string name); //building the AVL ->
        //insert helper function
        void searchID(Node* root, int id);
        void searchName(Node* root, string name, vector <long>& ids);

        Node* returnRoot();
        void setRoot(Node* node);

        BST();
        BST(Node* node);
        ~BST();
};

//insert each of the rows, artwork nodes, from the csv
Node* BST::insertNode(Node* node, int value, string value) { //CHANGE THE VALUE ACCORDING TO THE CSV

    if (node == nullptr) {
        return new Node(value, value);
    }
    else if (value == node->value) {
    }
    else if (value < node->value) {
        node->left = insertNode(node->left, value, value);
    }
    else {
        node->right = insertNode(node->right, value, value);
    }
    return node;
}

/****** search for the 3 different values below *****
 * 
 * values (name, id) are to be changed
 * 
 */

void BST::searchID(Node* root, int id) {

    Node* search = root;

    while (search != nullptr) {
        if (search->id == id) {
            cout << search->name << endl;
            break;
        } 
        else if (search->id < id) {
            search = search->left;
        } 
        else {
            search = search->right;
        }
    }

}

void BST::searchName(Node* root, string name, vector <long>& ids) { //return anything that matches

    if (root != nullptr) {
        if (root->name == name) {
            ids.push_back(root->id);
        }
        searchName(root->left, name, ids);
        searchName(root->right, name, ids);
    }

}

void BST::searchName(Node* root, string name, vector <long>& ids) { //return anything that matches

    if (root != nullptr) {
        if (root->name == name) {
            ids.push_back(root->id);
        }
        searchName(root->left, name, ids);
        searchName(root->right, name, ids);
    }

}