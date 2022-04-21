//
// Created by coler on 4/20/2022.
//

#ifndef MUSEUM_ENGINE_SPLAY_H
#define MUSEUM_ENGINE_SPLAY_H
class Splay{
public:
    Node* root;
    Splay();
    Node* getRoot();

    Node* rightRotate(Node* x);
    Node* leftRotate(Node* x);

    void splayHelper(Node* x);
    void insertHelper(ArtWork piece);
    Node* search(string id);
    Node* searchHelper(Node* root, string id);

    Node* splayID(Node* root, ArtWork piece);
    Node* splayTitle(Node* root, string id);
    Node* splayLink(Node* root, string id);

    Node* insNodeHelper(ArtWork piece);
    Node* insertID(Node* root, ArtWork piece);

    Node* searchID(Node* root, string id);
    Node* searchTitle(Node* root, string id);
    Node* searchLink(Node* root, string id);
};
#endif //MUSEUM_ENGINE_SPLAY_H
