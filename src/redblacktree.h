#include <iostream>
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
        Node* BSTInsertID(Node* root, Node* pt);
        void rotateLeft(Node *&root, Node *&pt);
        void rotateRight(Node *&root, Node *&pt);
        void fixViolation(Node *&root, Node *&pt);
        void insert(ArtWork piece);

        void searchID(Node* root, string id, vector <ArtWork>& result);
        void searchTitle(Node* root, string title, vector <string>& titles);
        void searchLink(Node* root, string link, vector <string>& links);
	Node* getRoot();

        RedBlackTree();
        RedBlackTree(Node* node);
};

