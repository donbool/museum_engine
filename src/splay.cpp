#include <iostream>
#include <string>
#include "artwork.cpp"
#include <string>

using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    Node* parent;

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

class Splay {
    Node* rootID = nullptr;
    Node* rootTitle = nullptr;
    Node* rootLink = nullptr;
public:
    Node* getRootID(){return rootID;}
    Node* getRootTitle(){return rootTitle;}
    Node* getRootLink(){return rootLink;}

    Splay();
    Node *rightRotate(Node *root)
    {
        Node *temp = root->left;
        root->left = temp->right;
        temp->right = root;
        return temp;
    }
    Node *leftRotate(Node *root)
    {
        Node *temp = root->right;
        root->right = temp->left;
        temp->left = root;
        return temp;
    }
    Node* splayID(Node *root, string id) {
        ArtWork rootWork = root->work;
        if (root == nullptr || rootWork.getID() == id)
            return root;

        if (rootWork.getID() > id)
        {
            if (root->left == nullptr) return root;

            if (root->left->work.getID() > id)
            {
                // First recursively bring the
                // key as root of left-left
                root->left->left = splayID(root->left->left, id);

                // Do first rotation for root,
                // second rotation is done after else
                root = rightRotate(root);
            }
            else if (root->left->work.getID() < id) // Zig-Zag (Left Right)
            {
                // First recursively bring
                // the key as root of left-right
                root->left->right = splayID(root->left->right, id);

                // Do first rotation for root->left
                if (root->left->right != nullptr)
                    root->left = leftRotate(root->left);
            }

            // Do second rotation for root
            return (root->left == nullptr)? root: rightRotate(root);
        }
        else // Key lies in right subtree
        {
            // Key is not in tree, we are done
            if (root->right == nullptr) return root;

            // Zag-Zig (Right Left)
            if (root->right->work.getID() > id)
            {
                root->right->left = splayID(root->right->left, id);

                // Do first rotation for root->right
                if (root->right->left != nullptr)
                    root->right = rightRotate(root->right);
            }
            else if (root->right->work.getID() < id)// Zag-Zag (Right Right)
            {
                root->right->right = splayID(root->right->right, id);
                root = leftRotate(root);
            }

            return (root->right == nullptr)? root: leftRotate(root);
        }
    }
    Node* splayTitle(Node *root, string title) {
        ArtWork rootWork = root->work;
        if (root == nullptr || rootWork.getTitle() == title)
            return root;

        if (rootWork.getTitle() > title)
        {
            if (root->left == nullptr) return root;

            if (root->left->work.getTitle() > title)
            {
                // First recursively bring the
                // key as root of left-left
                root->left->left = splayTitle(root->left->left, title);

                // Do first rotation for root,
                // second rotation is done after else
                root = rightRotate(root);
            }
            else if (root->left->work.getTitle() < title) // Zig-Zag (Left Right)
            {
                // First recursively bring
                // the key as root of left-right
                root->left->right = splayTitle(root->left->right, title);

                // Do first rotation for root->left
                if (root->left->right != nullptr)
                    root->left = leftRotate(root->left);
            }

            // Do second rotation for root
            return (root->left == nullptr)? root: rightRotate(root);
        }
        else // Key lies in right subtree
        {
            // Key is not in tree, we are done
            if (root->right == nullptr) return root;

            // Zag-Zig (Right Left)
            if (root->right->work.getTitle() > title)
            {
                root->right->left = splayTitle(root->right->left, title);

                // Do first rotation for root->right
                if (root->right->left != nullptr)
                    root->right = rightRotate(root->right);
            }
            else if (root->right->work.getTitle() < title)// Zag-Zag (Right Right)
            {
                root->right->right = splayTitle(root->right->right, title);
                root = leftRotate(root);
            }

            return (root->right == nullptr)? root: leftRotate(root);
        }
    }
    Node* splayLink(Node *root, string link) {
        ArtWork rootWork = root->work;
        if (root == nullptr || rootWork.getLink() == link)
            return root;

        if (rootWork.getLink() > link)
        {
            if (root->left == nullptr) return root;

            if (root->left->work.getLink() > link)
            {
                // First recursively bring the
                // key as root of left-left
                root->left->left = splayLink(root->left->left, link);

                // Do first rotation for root,
                // second rotation is done after else
                root = rightRotate(root);
            }
            else if (root->left->work.getLink() < link) // Zig-Zag (Left Right)
            {
                // First recursively bring
                // the key as root of left-right
                root->left->right = splayLink(root->left->right, link);

                // Do first rotation for root->left
                if (root->left->right != nullptr)
                    root->left = leftRotate(root->left);
            }

            // Do second rotation for root
            return (root->left == nullptr)? root: rightRotate(root);
        }
        else // Key lies in right subtree
        {
            // Key is not in tree, we are done
            if (root->right == nullptr) return root;

            // Zag-Zig (Right Left)
            if (root->right->work.getLink() > link)
            {
                root->right->left = splayLink(root->right->left, link);

                // Do first rotation for root->right
                if (root->right->left != nullptr)
                    root->right = rightRotate(root->right);
            }
            else if (root->right->work.getLink() < link)// Zag-Zag (Right Right)
            {
                root->right->right = splayLink(root->right->right, link);
                root = leftRotate(root);
            }

            return (root->right == nullptr)? root: leftRotate(root);
        }
    }

    Node *insertID(Node *root, ArtWork piece) {

        if (root == nullptr) {
            Node* pt = new Node(piece);
            return pt; //if tree empty
        }

        // Bring the closest leaf node to root
        root = splayID(root, piece.getID());
        ArtWork rootWork = root->work;
        // If key is already present, then return
        if (root->work.getID() == piece.getID()) return root;

        // Otherwise allocate memory for new node
        Node* pt = new Node(piece);
        // If root's key is greater, make
        // root as right child of newnode
        // and copy the left child of root to newnode
        if (rootWork.getID() > piece.getID())
        {
            pt->right = root;
            pt->left = root->left;
            root->left = nullptr;
        }

        else
        {
            pt->left = root;
            pt->right = root->right;
            root->right = nullptr;
        }

        return pt; // pt becomes new root
    }
    Node *insertTitle(Node *root, ArtWork piece) {

        if (root == nullptr) {
            Node* pt = new Node(piece);
            return pt; //if tree empty
        }

        // Bring the closest leaf node to root
        root = splayTitle(root, piece.getTitle());
        ArtWork rootWork = root->work;
        // If key is already present, then return
        if (root->work.getTitle() == piece.getTitle()) return root;

        // Otherwise allocate memory for new node
        Node* pt = new Node(piece);
        // If root's key is greater, make
        // root as right child of newnode
        // and copy the left child of root to newnode
        if (rootWork.getTitle() > piece.getTitle())
        {
            pt->right = root;
            pt->left = root->left;
            root->left = nullptr;
        }

        else
        {
            pt->left = root;
            pt->right = root->right;
            root->right = nullptr;
        }

        return pt; // pt becomes new root
    }
    Node *insertLink(Node *root, ArtWork piece) {

        if (root == nullptr) {
            Node* pt = new Node(piece);
            return pt; //if tree empty
        }

        // Bring the closest leaf node to root
        root = splayLink(root, piece.getLink());
        ArtWork rootWork = root->work;
        // If key is already present, then return
        if (root->work.getLink() == piece.getLink()) return root;

        // Otherwise allocate memory for new node
        Node* pt = new Node(piece);
        // If root's key is greater, make
        // root as right child of newnode
        // and copy the left child of root to newnode
        if (rootWork.getLink() > piece.getLink())
        {
            pt->right = root;
            pt->left = root->left;
            root->left = nullptr;
        }

        else
        {
            pt->left = root;
            pt->right = root->right;
            root->right = nullptr;
        }

        return pt; // pt becomes new root
    }

    Node* searchID(Node *root, string id) {
        return splayID(root, id);
    }

    Node* searchTitle(Node *root, string title) {
        return splayTitle(root, title);
    }

    Node* searchLink(Node *root, string link) {
        return splayLink(root, link);
    }
};

/* considering a splay tree works like any other BST with the priority of frequency, we need to construct three trees:
 * 1. ranks id
 * 2. ranks title
 * 3. ranks link
 * Since each piece of data in the artwork object is different, the strings have differing values and cannot be used interchangeably in searching methods
 */