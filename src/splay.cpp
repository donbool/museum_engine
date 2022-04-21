#include "splay.h"

Node* Splay::getRoot(){return root;}
Splay::Splay(){
	root = nullptr;
}
void Splay::rightRotate(Node *x)
    {
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
void Splay::leftRotate(Node* x)
{
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
    void Splay::splayHelper(Node *x) {
        while (x->parent) {
            if (!x->parent->parent) {
                if (x == x->parent->left) {
                    // zig rotation
                    rightRotate(x->parent);
                } else {
                    // zag rotation
                    leftRotate(x->parent);
                }
            } else if (x == x->parent->left && x->parent == x->parent->parent->left) {
                // zig-zig rotation
                rightRotate(x->parent->parent);
                rightRotate(x->parent);
            } else if (x == x->parent->right && x->parent == x->parent->parent->right) {
                // zag-zag rotation
                leftRotate(x->parent->parent);
                leftRotate(x->parent);
            } else if (x == x->parent->right && x->parent == x->parent->parent->left) {
                // zig-zag rotation
                leftRotate(x->parent);
                rightRotate(x->parent);
            } else {
                // zag-zig rotation
                rightRotate(x->parent);
                leftRotate(x->parent);
            }
        }
}
void Splay::insertHelper(ArtWork piece) {
    // normal BST insert
    Node* node = new Node(piece);
    node->parent = nullptr;
    node->left = nullptr;
    node->right = nullptr;

    Node* y = nullptr;
    Node* x = this->root;

    while (x != nullptr) {
        y = x;
        if (node->work.getID() < x->work.getID()) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    // y is parent of x
    node->parent = y;
    if (y == nullptr) {
        root = node;
    } else if (node->work.getID() < y->work.getID()) {
        y->left = node;
    } else {
        y->right = node;
    }

    // splay the node
    //splayHelper(node);
}
Node* Splay::searchHelper(Node* root, string id) {
    if (root == nullptr || root->work.getID().compare(id) == 0) {
        return root;
    }

    if (id < root->work.getID()) {
        return searchHelper(root->left, id);
    }
    return searchHelper(root->right, id);
}
Node* Splay::search(string id) {
    Node* found = searchHelper(this->root,id);
    if(found == nullptr)
        return found;
    else{
        //splayHelper(found);
        return found;
    }
}
/*Node* Splay::splayID(Node *root, ArtWork piece) {
        ArtWork rootWork = root->work;
        if (root == nullptr || rootWork.getID() == piece.getID()){
            return root;

        }

        if (rootWork.getID() > piece.getID())
        {
            if (root->left == nullptr) return root;

            if (root->left->work.getID() > piece.getID())
            {
                // First recursively bring the
                // key as root of left-left
                root->left->left = splayID(root->left->left, piece.getID());

                // Do first rotation for root,
                // second rotation is done after else
                root = rightRotate(root);
            }
            else if (root->left->work.getID() < piece.getID()) // Zig-Zag (Left Right)
            {
                // First recursively bring
                // the key as root of left-right
                root->left->right = splayID(root->left->right, piece.getID());

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
            if (root->right->work.getID() > piece.getID())
            {
                root->right->left = splayID(root->right->left, piece.getID());

                // Do first rotation for root->right
                if (root->right->left != nullptr)
                    root->right = rightRotate(root->right);
            }
            else if (root->right->work.getID() < piece.getID())// Zag-Zag (Right Right)
            {
                root->right->right = splayID(root->right->right, piece.getID());
                root = leftRotate(root);
            }

            return (root->right == nullptr)? root: leftRotate(root);
        }
    }
    */
/*Node* Splay::splayTitle(Node *root, string title) {
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
    */
/*Node* Splay::splayLink(Node *root, string link) {
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
    */

Node* Splay::insNodeHelper(ArtWork piece) {
    Node* newNode = new Node(piece);
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
/*Node* Splay::insertID(Node *root, ArtWork piece) {

        if (root == nullptr) {
            return insNodeHelper(piece);//if tree empty
        }

        // Bring the closest leaf node to root
        root = splayID(root, piece.getID());

        // If key is already present, then return
        if (root->work.getID() == piece.getID()) return root;

        // Otherwise allocate memory for new node
        Node* pt = insNodeHelper(piece);

        if (root->work.getID() > piece.getID())
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
    */
/*Node* Splay::insertTitle(Node *root, ArtWork piece) {

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
    }*/
/*Node* Splay::insertLink(Node *root, ArtWork piece) {

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
    }*/

/*Node* Splay::searchID(Node *root, string id) {
        return splayID(root, id);
    }

Node* Splay::searchTitle(Node *root, string title) {
        return splayTitle(root, title);
    }

Node* Splay::searchLink(Node *root, string link) {
        return splayLink(root, link);
    }
    */


/* considering a splay tree works like any other BST with the priority of frequency, we need to construct three trees:
 * 1. ranks id
 * 2. ranks title
 * 3. ranks link
 * Since each piece of data in the artwork object is different, the strings have differing values and cannot be used interchangeably in searching methods
 */
