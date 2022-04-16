#include <iostream>
#include <string>
using namespace std;

class Node {
    public:
        Node* left;
        Node* right;
        Node* parent;

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
            country = "";
            link = "";
        }

        Node(string id, string objectName, string title, string culture, int objectYear, string link) {
            left = nullptr;
            right = nullptr;
            this->id = id;
            this->title = title;
            this->culture = culture;
            this->objectYear = objectYear;
            this->link = link;
        }
};
 
Node* newNode(string key)
{
    Node* node = new Node();
    node->id = key;
    node->left = node->right = NULL;
    return (node);
}
 
// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
Node *rightRotate(Node *x)
{
    Node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}
 
// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}
 
// This function brings the key at root if key is present in tree.
// If key is not present, then it brings the last accessed item at root. 
// This function modifies the tree and returns the new root
Node* splay(Node *root, string id) {
    // Base cases: root is NULL or
    // key is present at root
    if (root == NULL || root->id == id)
        return root;
 
    // Key lies in left subtree
    if (root->id > id)
    {
        // Key is not in tree, we are done
        if (root->left == NULL) return root;
 
        // Zig-Zig (Left Left)
        if (root->left->id > id)
        {
            // First recursively bring the
            // key as root of left-left
            root->left->left = splay(root->left->left, id);
 
            // Do first rotation for root,
            // second rotation is done after else
            root = rightRotate(root);
        }
        else if (root->left->id < id) // Zig-Zag (Left Right)
        {
            // First recursively bring
            // the key as root of left-right
            root->left->right = splay(root->left->right, id);
 
            // Do first rotation for root->left
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }
 
        // Do second rotation for root
        return (root->left == NULL)? root: rightRotate(root);
    }
    else // Key lies in right subtree
    {
        // Key is not in tree, we are done
        if (root->right == NULL) return root;
 
        // Zag-Zig (Right Left)
        if (root->right->id > id)
        {
            // Bring the key as root of right-left
            root->right->left = splay(root->right->left, id);
 
            // Do first rotation for root->right
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        else if (root->right->id < id)// Zag-Zag (Right Right)
        {
            // Bring the key as root of
            // right-right and do first rotation
            root->right->right = splay(root->right->right, id);
            root = leftRotate(root);
        }
 
        // Do second rotation for root
        return (root->right == NULL)? root: leftRotate(root);
    }
}

Node *insert(Node *root, string k) {

    if (root == NULL) {
        return newNode(k); //if tree empty
    }

    // Bring the closest leaf node to root
    root = splay(root, k);
 
    // If key is already present, then return
    if (root->id == k) return root;
 
    // Otherwise allocate memory for new node
    Node* newnode = newNode(k);
 
    // If root's key is greater, make
    // root as right child of newnode
    // and copy the left child of root to newnode
    if (root->id > k)
    {
        newnode->right = root;
        newnode->left = root->left;
        root->left = NULL;
    }
 
    // If root's key is smaller, make
    // root as left child of newnode
    // and copy the right child of root to newnode
    else
    {
        newnode->left = root;
        newnode->right = root->right;
        root->right = NULL;
    }
 
    return newnode; // newnode becomes new root
}
 
// The search function for Splay tree.
// Note that this function returns the
// new root of Splay Tree. If key is
// present in tree then, it is moved to root.
Node* searchID(Node *root, string id) {
    return splay(root, id);
}

Node* searchTitle(Node *root, string title) {
    return splay(root, title);
}

Node* searchLink(Node *root, string link) {
    return splay(root, link);
}