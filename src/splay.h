//
// Created by coler on 4/20/2022.
//

#ifndef MUSEUM_ENGINE_SPLAY_H
#define MUSEUM_ENGINE_SPLAY_H
class Splay{
    Node* rootID,rootTitle,rootLink;
public:
    Splay();
    Node* getRootID();
    Node* getRootTitle();
    Node* getRootLink();

    Node* rightRotate();
    Node* leftRotate();

    Node* splayID(Node* root, string id);
    Node* splayTitle(Node* root, string id);
    Node* splayLink(Node* root, string id);

    Node* insertID(Node* root, ArtWork piece);
    Node* insertTitle(Node* root, ArtWork piece);
    Node* insertLink(Node* root, ArtWork piece);

    Node* searchID(Node* root, string id);
    Node* searchTitle(Node* root, string id);
    Node* searchLink(Node* root, string id);
};
#endif //MUSEUM_ENGINE_SPLAY_H
