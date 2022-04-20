//
// Created by coler on 4/20/2022.
//

#ifndef MUSEUM_ENGINE_SPLAY_H
#define MUSEUM_ENGINE_SPLAY_H
class Splay{
private:
    Node* root;
public:
    Splay();
    Node* getRoot();

    Node* rightRotate(Node* root);
    Node* leftRotate(Node* root);

    Node* splayID(Node* root, string id);
    Node* splayTitle(Node* root, string id);
    Node* splayLink(Node* root, string id);

    Node* insNodeHelper(ArtWork piece);
    Node* insertID(Node* root, ArtWork piece);

    Node* searchID(Node* root, string id);
    Node* searchTitle(Node* root, string id);
    Node* searchLink(Node* root, string id);
};
#endif //MUSEUM_ENGINE_SPLAY_H
